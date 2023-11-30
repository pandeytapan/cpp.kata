#include <iostream>
#include <vector>

struct DataRun {
    uint64_t cluster_count;
    int64_t start_cluster;
    int32_t lcn_size;
};

// Define NTFS_RUN as an alias for std::vector<DataRun>
using NTFS_RUN = std::vector<DataRun>;




int64_t pad_negative(uint64_t u64_num, uint8_t size)
{
    const std::vector<uint64_t> vec_vcn_sign_extender = { 
        0xFFFFFFFFFFFFFF80, /*8 -BIT*/
        0xFFFFFFFFFFFF8000, /*16-BIT*/
        0xFFFFFFFFFF800000, /*24-BIT*/
        0xFFFFFFFF80000000, /*32-BIT*/
        0xFFFFFF8000000000, /*40-BIT*/
        0xFFFF800000000000, /*48-BIT*/
        0xFF80000000000000, /*56-BIT*/
        0x8000000000000000  /*64-BIT*/
    };

    auto n_mask = (vec_vcn_sign_extender[size-1] << (64 - size * 8));
    n_mask >>= (64 - size * 8);
    int64_t u64_padded = (u64_num & n_mask) ? u64_num | vec_vcn_sign_extender[size-1]: u64_num;

    return u64_padded;
}

std::vector<DataRun> parse_runlist(const unsigned char* runlist, size_t size) {
    std::vector<DataRun> runs;
    size_t pos = 0;
    while (pos < size) {
        unsigned char length_byte = runlist[pos++];
        if (length_byte == 0) {
            break;
        }
        int length = length_byte & 0x0f;
        int offset = length_byte >> 4;
        uint64_t cluster_count = 0;
        for (int i = 0; i < length; i++) {
            cluster_count |= ((uint64_t)runlist[pos++] << (i * 8));
        }
        int64_t lcn_offset = 0;
        if ((offset & 8) != 0) {
            lcn_offset = -1;
        }
        for (int i = 0; i < (offset & 7); i++) {
            lcn_offset |= ((int64_t)runlist[pos++] << (i * 8));
        }
        runs.push_back({ cluster_count, lcn_offset, offset });
    }
    return runs;
}

// Convert a virtual cluster number (VCN) to a logical cluster number (LCN) using the given runlist
void vcn_to_lcn(NTFS_RUN& runlist) {
    uint64_t offset = 0;
    auto it = runlist.begin();
    ++it; // First runis always LCN
    
    for (; it != runlist.end(); ++it) {
        it->start_cluster = pad_negative(it->start_cluster, it->lcn_size);
    }
}

int main() {

    unsigned char runlist[] = {
        0x33, 0xBF, 0x04, 0x02, 0x40, 0xB5, 0x01,
        0x32, 0xBC, 0x53, 0x56, 0x50, 0xFE
    };
    // uint8_t bytes[] = {0xFF, 0x18, 0x83};
    // uint32_t padded_value = (bytes[0] << 16) | (bytes[1] << 8) | bytes[2]; // padded with 0xFF
    // int32_t signed_value = *(int32_t*)(&padded_value); // interpret as signed long value
    // std::cout << "Padded value: " << std::hex << padded_value << std::endl;
    // std::cout << "Signed value: " << std::dec << signed_value << std::endl;
    // return 0;
    // unsigned char runlist[] = {
    //     0x31, 0x01, 0x2F, 0xEE, 0x01,           /*LCN*/
    //     0x31, 0x03, 0x3E, 0x56, 0x12,           /*VCN 1*/
    //     0x11, 0x04, 0xBB,                       /*VCN 2*/
    //     0x11, 0x08, 0x70,                       /*VCN 3*/
    //     0x31, 0x10, 0xE8, 0xA6, 0xEC,           /*VCN 4*/
    //     0x21, 0x10, 0x48, 0xC7,                 /*VCN 5*/
    //     0x31, 0x10, 0x78, 0x3A, 0x2F,           /*VCN 6*/
    //     0x31, 0x11, 0xC4, 0x89, 0xF9,           /*VCN 7*/
    //     0x32, 0xAC, 0x00, 0x9D, 0x0C, 0xF6      /*VCN 8*/
    //     };
    std::vector<DataRun> runs = parse_runlist(runlist, sizeof(runlist));

    vcn_to_lcn(runs);
    return 0;
}

class Point_010
{
  public:
    //   attributes
    int m_nX;
    int m_nY;
    // Overrides

    Point_010(/* args */);
    Point_010(int nX, int nY);
    const char *const quadrant();
};

Point_010 ::Point_010()
{
    m_nX = 0;
    m_nY = 0;
}

Point_010 ::Point_010(int nX, int nY)
{
    m_nX = nX;
    m_nY = nY;
}

const char *const Point_010 ::quadrant()
{
    if (m_nX > 0 && m_nY > 0)
        return "First";
    else if (m_nX)
}
def is_point_in_polygon(point, polygon):
    """
    pointがpolygonの内部にあるかをcrossing number algorithmで判定する。

    Parameters
    ----------
    point : list
        判定したい座標
        ex. [100,200]
    polygon : list
        ポリゴン
        ex. [(0,1), (1,1), (1,2), (2,2), (2,3), (3,3), (3,2), (4,0), (5,9), (6,0)]

    Returns
    -------
    is_inside : bool
        True == 内部
        False == 外部
    """

    is_inside = False

    for i1 in range(len(polygon)):
        i2 = 0 if i1 == len(polygon) - 1 else i1 + 1
        if min(polygon[i1][0], polygon[i2][0]) < point[0] < max(polygon[i1][0], polygon[i2][0]):
            if (polygon[i1][1] + (polygon[i2][1] - polygon[i1][1]) / (polygon[i2][0] - polygon[i1][0]) * (point[0] - polygon[i1][0]) - point[1]) > 0:
                is_inside = not is_inside

    return is_inside


def test():
    point = [10, 10]
    polygon = [[0, 0], [35, 5], [30, 35], [5, 35], [0, 30]]
    print(is_point_in_polygon(point, polygon))


if __name__ == '__main__':
    test()

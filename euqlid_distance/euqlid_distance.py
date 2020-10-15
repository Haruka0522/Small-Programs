import numpy as np


def calc_euclid_distance(A, B):
    """
    ユークリッド距離を求める

    Parameters
    ---------
    A : numpy.ndarray
    B : numpy.ndarray

    Return
    ------
    euclid_distance : numpy.float64
    """

    return np.sqrt(np.power(A - B, 2).sum())


if __name__ == '__main__':
    A = np.array([1, 1])
    B = np.array([2, 2])
    print(calc_euclid_distance(A, B))

    C = np.array([1, 1, 1])
    D = np.array([2, 2, 2])
    print(calc_euclid_distance(C, D))

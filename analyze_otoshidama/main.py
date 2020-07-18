import pandas as pd
import matplotlib.pyplot as plt
from sklearn import linear_model


class OtoshidamaAnalyzer():
    def __init__(self, data_path):
        self.df = pd.read_csv(data_path, encoding="UTF8")

    def linear_regression(self):
        clf = linear_model.LinearRegression()
        x = self.df.loc[:, ["age"]]
        y = self.df.loc[:, ["total_amount"]]
        clf.fit(x, y)
        # 回帰係数
        print(clf.coef_)
        self.coef = clf.coef_
        # 切片
        print(clf.intercept_)
        self.intercept = clf.intercept_
        # 決定係数
        print(clf.score(x, y))

        # plot
        self.df.plot(x="age", y="total_amount")
        plt.plot(x, clf.predict(x))
        plt.scatter(x, y)
        plt.show()

    def search_requirements_age(self, target):
        age = 1
        while True:
            if age * self.coef + self.intercept >= target:
                return age
            if age >= 10**8:
                print("over 10^8 age")
                return None
            age += 1

    def predict_from_age(self, age):
        return age * self.coef + self.intercept


if __name__ == '__main__':
    constracta = OtoshidamaAnalyzer("data.csv")
    constracta.linear_regression()
    print(constracta.search_requirements_age(1000000))
    print(constracta.predict_from_age(100))

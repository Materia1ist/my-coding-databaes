coffee = [0, 1, 2, 3, 4]
study = [1, 2, 3, 4, 5]
score = [60, 70, 80, 85, 90]

def correlation(x, y):
    n = len(x)
    mean_x,mean_y = sum(x) / n, sum(y) / n
    num = sum((x[i] - mean_x) * (y[i] - mean_y) for i in range(n))
    den = (sum((xi - mean_x) ** 2 for xi in x) * sum((yi - mean_y) ** 2 for yi in y)) ** 0.5
    return num / den if den != 0 else 0

def skewness(x):
    n = len(x)
    x_mean = sum(x) / n
    s = (sum((x_i - x_mean) ** 2 for x_i in x) / n) ** 0.5
    ans = sum(((x_i - x_mean)/s) ** 3 for x_i in x) / n
    return ans

def kurtosis(x):
    n = len(x)
    x_mean = sum(x) / n
    s = (sum((x_i - x_mean) ** 2 for x_i in x) / n) ** 0.5
    ans = sum(((x_i - x_mean)/s) ** 4 for x_i in x) / n
    return ans

print("咖啡 vs 成绩:", correlation(coffee, score))
print("学习 vs 成绩：", correlation(study, score))
print("kurtosis of score:", kurtosis(score))
print("kurtosis of coffee:", kurtosis(coffee))
print("kurtosis of study:", kurtosis(study))
print("skewness of score:", skewness(score))
print("skewness of coffee:", skewness(coffee))  
print("skewness of study:", skewness(study))
x = 1+2
print("1 + 2 =", x)
input("程序执行完毕，按回车键退出...")
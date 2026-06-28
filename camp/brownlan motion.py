import numpy as np
import matplotlib.pyplot as plt

def brownian_bridge(n, T, a=0, b=0):
    dt = T / n
    t = np.linspace(0, T, n + 1)
    dW = np.random.normal(0, np.sqrt(dt), n)
    W = np.concatenate(([0], np.cumsum(dW)))
    # 布朗桥公式
    bridge = a + (W + (t / T) * (b - W[-1] - a))
    return t, bridge

if __name__ == "__main__":
    n = 1000
    T = 10
    a = 0   # 起点
    b = 5   # 终点
    for _ in range(10):
        t, bridge = brownian_bridge(n, T, a, b)
        plt.plot(t, bridge)
    plt.title("Brownian Bridge (start at a, end at b)")
    plt.xlabel("Time")
    plt.ylabel("Position")
    plt.show()
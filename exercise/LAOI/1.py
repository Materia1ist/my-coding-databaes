from itertools import permutations

def solve_n3():
    n = 3
    # 生成 1 到 n 的所有排列
    elements = list(range(1, n + 1))
    all_perms = list(permutations(elements))
    
    # 转换为集合以便快速判断 w 是否为 1~n 的排列
    target_set = set(elements)
    
    success_count = 0
    print(f"--- n = {n} 的成功情况打表 ---")
    print(f"{'x 排列':<10} | {'y 排列':<10} | {'z 排列':<10} => {'w 排列':<10}")
    print("-" * 55)
    
    # 枚举 x, y, z 的排列组合
    for x in all_perms:
        for y in all_perms:
            for z in all_perms:
                # 计算 w_i = x_i - y_i + z_i
                w = tuple(xi - yi + zi for xi, yi, zi in zip(x, y, z))
                
                # 检查 w 的每个元素是否在 1~n 内，且没有重复元素（即构成排列）
                if len(set(w)) == n and all(1 <= wi <= n for wi in w):
                    success_count += 1
                    print(f"{str(x):<10} | {str(y):<10} | {str(z):<10} => {str(w):<10}")
                    
    print("-" * 55)
    print(f"n = {n} 时，满足条件的三元组总数为: {success_count}")

if __name__ == "__main__":
    solve_n3()
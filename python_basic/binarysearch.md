
# 🔍 二分探索コードの整理（2025/04/21）

---

## 📚 区間について

- 開区間: `left < a < right` → `(left, right)`
- 閉区間: `left <= a <= right` → `[left, right]`

---

## ✅ 二分探索を利用する場面

- ソートされた数列に対して、条件を満たすかどうかが単調的な場合。
- 単調的な場合とは：
  - `True → False` または `False → True` の切り替えが1回だけある。
  - 境界がどこかに1個だけあり、それ以前（または以降）はずっと同じ判定結果である。
- 基本的には整数しか扱わない：
  - `while` 条件の終了が `left == right` にならないと無限ループの可能性があるため。
  - 浮動小数点を扱う場合は、`for` で許容される誤差範囲になるまで回数を決めて回す。

---

## 🎯 二分探索のコツ

- 答えとなるものを必ず二分探索する。
- 二重の関数になる時はそれぞれで止まるものを明確にする。
- `True → False` の流れと境界値がどちら側かを確認する：

  ```
  True * → False：True を満たす最大
  ⇔ False * → True：False を満たす最大（条件を反転するだけ）
  False → * True：True を満たす最小
  ⇔ True → * False：False を満たす最小（条件を反転するだけ）
  ```

- 求めたいものに応じて、以下を選ぶ：
  1. `while` 条件
  2. 条件による `left`, `right` の更新方法（範囲の狭め方）
  3. `return` で返すもの

---

## 🔽 True を満たす最小を探す

### 【典型コード①】

- 半開区間 `[left, right)` で、`left` をじわじわ進めて `right` に追いつくまで狭めていく。
- `left` は解に向かって前進する。
- `right` は固定（常に True の保証がある）。
- `right` はその時の答え候補。
- `left == right` になったら探索終了。

```python
while left < right:
    mid = (left + right) // 2
    if is_ok(mid):
        right = mid  # mid は True の範囲
    else:
        left = mid + 1  # mid は False の範囲
return left
```

---

### 【典型コード②】

- 閉区間 `[left, right]` の両端を固定し、範囲を狭めていく（常に left = False, right = True の保証がある）。
- 実質的には開区間 `(left, right)` のようなイメージ。
- `while` が成り立つ間は `left < mid < right` が保証され、毎回範囲を狭める。

```python
left = definitely False
right = definitely True
while right - left > 1:
    mid = (left + right) // 2
    if is_ok(mid):
        right = mid  # mid も True 側
    else:
        left = mid   # mid は False 側
return right
```

---

## 🔼 True を満たす最大を探す

### 【典型コード①】

- 閉区間 `[left, right]` で、両方からじわじわ進めて狭めていく。
- `left`, `right` ともに動くため、`mid` を記録しておく必要がある。
- `ans` に直近の OK を保持。
- `left > right` で終了。

```python
ans = -1
while left <= right:
    mid = (left + right) // 2
    if is_ok(mid):
        ans = mid
        left = mid + 1
    else:
        right = mid - 1
return ans
```

---

### 【典型コード②】

- 閉区間 `[left, right]` の両端を固定し、範囲を狭めていく（常に left = True, right = False の保証がある）。
- 実質的には開区間 `(left, right)` のようなイメージ。
- `while` 中は `left < mid < right` が常に成り立つ。

```python
left = definitely True
right = definitely False
while right - left > 1:
    mid = (left + right) // 2
    if is_ok(mid):
        left = mid
    else:
        right = mid
return left
```

---
### 二分探索の問題とその検討
[704. Binary Serach](https://leetcode.com/problems/binary-search/editorial)

> 作成日: 2025年4月21日  
> ファイル名: `250421_binarysearch.md`

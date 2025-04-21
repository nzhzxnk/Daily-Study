
# 🔍 Binary Search Cheatsheet

A comprehensive guide to implementing binary search patterns for finding boundaries in monotonic conditions.

---

## 📚 Interval Definitions

- **Open interval**: `(left, right)` means `left < x < right`
- **Closed interval**: `[left, right]` means `left <= x <= right`

---

## ✅ When to Use Binary Search

- Applicable when conditions are **monotonic**:
  - Either `False → True` or `True → False` with a **single transition point**
- Must identify the **boundary** where this change occurs
- Typically works best with **integers**
  - Avoids floating-point precision issues and infinite loops
- For floating-point domains, use a `for` loop with an acceptable **error threshold** instead of a `while` loop

---

## 🎯 Binary Search Principles

- Always **binary search over the answer**, not the index blindly.
- For nested functions, clearly define which part terminates the condition.
- Know the direction of monotonicity and where the boundary lies:
  - `True * → False`: Max of True
  - `False * → True`: Min of True
- For any search goal, tailor:
  1. The `while` condition
  2. The update rules
  3. The final return value

---

## 🔽 Finding the **Minimum Value that Satisfies `is_ok()`**

### 🔹 Template 1 – Half-open interval `[left, right)`

```python
while left < right:
    mid = (left + right) // 2
    if is_ok(mid):
        right = mid  # mid is in True region
    else:
        left = mid + 1  # mid is in False region
return left
```

- `left` moves forward toward the solution
- `right` holds the current best candidate (guaranteed to be True)
- Terminates when `left == right`

---

### 🔹 Template 2 – Explicit NG/OK boundaries `(left, right)`

```python
left = NG  # definitely False
right = OK  # definitely True
while right - left > 1:
    mid = (left + right) // 2
    if is_ok(mid):
        right = mid  # True region
    else:
        left = mid   # False region
return right
```

- Ensures `left < mid < right` on each iteration
- Returns the first `x` for which `is_ok(x) == True`

---

## 🔼 Finding the **Maximum Value that Satisfies `is_ok()`**

### 🔹 Template 1 – Closed interval `[left, right]` with memo

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

- Use `ans` to track the latest valid `mid` because both ends move

---

### 🔹 Template 2 – Explicit OK/NG boundaries `(left, right)`

```python
left = OK  # definitely True
right = NG  # definitely False
while right - left > 1:
    mid = (left + right) // 2
    if is_ok(mid):
        left = mid
    else:
        right = mid
return left
```

- Returns the **last** position where `is_ok(x) == True`

---

## 🧠 Bonus Tips

- Choose the right interval based on where the answer lies (inclusive or exclusive)
- Use `right - left > 1` style for clean, precise boundaries
- For floats: switch to `for`-loop with convergence like `abs(right - left) < EPS`

---

> Created: 2025-04-21  
> Filename: `binary_search_cheatsheet.md`

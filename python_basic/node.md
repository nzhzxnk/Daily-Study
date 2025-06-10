
## ノード(連結リスト)

一般的なノードの概念（例: 連結リスト、ツリー）についてです。

* **ノードの作成**:
    ```python
    # 例えば ListNode というクラスがあるとして
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    a = ListNode(1) # 1という値を持つノードを作成
    ```
* **ノードの連結**:
    ```python
    b = ListNode(2)
    b.next = a  # b -> a という連結リストを作成
    # または、初期化時に連結
    c = ListNode(3, b) # c -> b -> a という連結リストを作成
    ```
* **ノードの辿り方**:
    先頭のノード（`head` など）から `.next` を繰り返すことで、リストを辿ることができます。
    ```python
    # c が先頭ノードの場合
    current = c
    while current:
        print(current.val)
        current = current.next
    # 出力: 3, 2, 1
    ```
* **ノードの切り離し/再割り当て**:
    変数への代入によって、ノードの参照を変更し、連結リストの構造を変更できます。
    ```python
    # 例えば c -> b -> a の状態から、b -> a のリストを新しいヘッドにする
    new_head = c.next # new_head は b を指す
    # または、リストの途中から切り離す場合など
    # some_node.next = None
    ```
## 木 (Tree) の基礎

* **根ノード (Root Node)**: 親を持たない唯一のノードです。木構造の最上位に位置します。
* **木の走査 (Traversal)**:
    * **中順走査 (Inorder Traversal)**: 左の子 → 自分（現在のノード） → 右の子 の順でノードを辿ります。再帰的に行われます。
        1.  左の子へ「行けるなら行く」
        2.  行けなくなったら「今のノードを記録」
        3.  右の子がいれば「右へ行く」

```python
# TreeNode クラスの例 (LeetCodeなどでよく使われる形式)
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 木の作成例
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
# この場合、TreeNode(1) が root になります。
```
`[1, 2, 3]` のような配列形式の入力は、通常、BFS (幅優先探索) 順に木のノードの値を並べていることを意味し、最初の要素がルートノードになるという前提が多いです（例: LeetCode）。

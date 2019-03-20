import java.util.List;

public class BST {
    public static Node insert(Node root, int key) {
        if (root == null)
            return new Node(key);
        else if (key == root.key)
            return root;
        else if (key < root.key) {
            root.left = insert(root.left, key);
            return root;
        }
        else {
            root.right = insert(root.right, key);
            return root;
        }
    }

    public static Node createBST(int[] keys) {
        Node root = null;
        for (int key : keys)
            root = insert(root, key);
        return root;
    }
    public static Node createBST(List<Integer> keys) {
        Node root = null;
        for (int key : keys)
            root = insert(root, key);
        return root;
    }
}
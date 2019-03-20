public class InorderTraversal  {
    public static void inorderTraverse(Node root) {
        if (root != null) {
            inorderTraverse(root.left);
            System.out.println(root.key + " ");
            inorderTraverse(root.right);
        }
    }
}
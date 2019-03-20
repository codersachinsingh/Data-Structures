public class PostOrderTraversal {
    public static void postorderTraverse(Node root) {
        if (root != null) {
            postorderTraverse(root.left);
            postorderTraverse(root.right);
            System.out.print(root.key + " ");
        }
    }
}
public class PreOrderTraversal {
    public static void preorderTraverse(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preorderTraverse(root.left);
            preorderTraverse(root.right);
        }
    }
}
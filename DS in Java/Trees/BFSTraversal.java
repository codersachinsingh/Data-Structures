import java.util.ArrayDeque;
import java.util.Queue;

public class BFSTraversal {
    public static void breadthFirstTraverse(Node root) {
        if (root != null) {
            Queue<Node> queue = new ArrayDeque<>();
            queue.add(root);
            while (!queue.isEmpty()) {
                Node node = queue.poll();
                if (node.left != null)
                    queue.add(node.left);
                if (node.right != null)
                    queue.add(node.right);
                System.out.print(node.key + " ");
            }
        }
    }
}
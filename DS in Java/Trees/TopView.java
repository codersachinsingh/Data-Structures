import java.util.ArrayDeque;
import java.util.Map;
import java.util.Queue;
import java.util.Stack;
import java.util.TreeMap;

public class TopView {
    public static void topview(Node root) {
        class NodePack {
            Node node;
            int level;
            NodePack(Node node, int lvl) {
                this.node = node;
                this.level = lvl;
            }
        }

        if (root != null) {
            Queue<NodePack> queue = new ArrayDeque<>();
            Map<Integer, Node> map = new TreeMap<>();
            queue.add(new NodePack(root, 0));
            while (!queue.isEmpty()) {
                NodePack pack = queue.poll();
                Node node = pack.node;
                int level = pack.level;

                if (!map.containsKey(level)) {
                    System.out.print(node.key + " ");
                    map.put(level, node);
                }

                if (node.left != null) {
                    queue.add(new NodePack(node.left, level-1));
                }

                if (node.right != null) {
                    queue.add(new NodePack(node.right, level + 1));
                }
            }
        }
    }

    public static void topviewleftright(Node root) {
        if (root != null) {
            Stack<Integer> stack = new Stack<>();
            Node l = root.left;
            while (l != null) {
                stack.push(l.key);
                l = l.left;
            }
            while (!stack.isEmpty())
                System.out.print(stack.pop() + " ");
            while (root != null) {
                System.out.print(root.key + " ");
                root = root.right;
            }
        }     
    }
}
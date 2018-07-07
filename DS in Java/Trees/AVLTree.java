/**
 * AVL Tree is a <b>self balancing</b> binary search tree.
 * value is inserted with a unique key (key/value pair).
 * value is retrieved by giving the key corresponding to that value.
 * insertion , deletion , searching all done is <i>O(log(n))</i> complexity.
 *
 * @author Sachin Singh
 * @version 1.0
 * */
public class AVLTree {

    /**
     * Node is a inner private class of <b>AVL Tree</b> whose objects stores the key/value pair with
     * some other information which includes references to left child and right child
     * height of that node and total number of nodes in subtrees.
     * @author Sachin Singh
     * @version 1.0
     * */
    private class Node {
        int data;
        int key;
        int height;
        int size;
        Node left , right;
        /**
         * Creates a node with specified key and value.
         * */

        Node(int key , int data) {
            this.key = key;
            this.data = data;
            height = size = 1;
        }

        /**
         * Returns a String that represents the node (Contains Key , Value , Height and Size information)
         * */
        @Override
        public String toString() {
            return "Key : " + this.key + " | Data : " + this.data + " | Height : " + this.height + "| Size : " + this.size;
        }
    }

    private Node root;
    private int getHeight(Node node) {
        if (node != null)
            return node.height;
        return 0;
    }
    private int getSize(Node node) {
        if (node != null)
            return node.size;
        return 0;
    }
    private void setSize(Node node) {
        if (node != null)
            node.size = getSize(node.left) + getSize(node.right) + 1;
    }
    private int getBalance(Node node) {
        if (node != null)
            return getHeight(node.left) - getHeight(node.right);
        return 0;
    }
    private Node getMaximumKeyNode(Node root) {
        if (root.right != null)
            return getMaximumKeyNode(root.right);
        else
            return root;
    }
    private void setHeight(Node node) {
        if (node != null)
            node.height = Math.max(getHeight(node.left), getHeight(node.right)) + 1;
    }

    private Node leftRotation(Node subRoot) {
        Node newRoot = subRoot.right;
        Node node = newRoot.left;
        newRoot.left = subRoot;
        subRoot.right = node;
        // update height
        setHeight(subRoot);
        setHeight(newRoot);
        //update size
        setSize(subRoot);
        setSize(newRoot);
        return newRoot;
    }

    private Node rightRotation(Node subRoot) {
        Node newRoot = subRoot.left;
        Node node = newRoot.right;
        newRoot.right = subRoot;
        subRoot.left = node;
        // update height
        setHeight(subRoot);
        setHeight(newRoot);
        //update size
        setSize(subRoot);
        setSize(newRoot);
        return newRoot;
    }

    private Node insert(Node loc, int key, int data) {
        if (loc == null)
            return new Node(key,data);
        else if (key < loc.key) {
            loc.left = insert(loc.left,key,data);
            setHeight(loc);
            setSize(loc);
        }
        else {
            loc.right = insert(loc.right,key,data);
            setHeight(loc);
            setSize(loc);
        }
        int balanceFactor = getBalance(loc);

        // LL rotation
        if (balanceFactor > 1 && key < loc.left.key)  {
            return rightRotation(loc);
        }

        //RL rotation
        if (balanceFactor > 1 && key > loc.left.key) {
            loc.left = leftRotation(loc.left);
            return rightRotation(loc);
        }

        //LR rotation
        if (balanceFactor < -1 && key < loc.right.key) {
            loc.right = rightRotation(loc.right);
            return leftRotation(loc);
        }

        // RR rotation
        if (balanceFactor < -1 && key > loc.right.key) {
            return leftRotation(loc);
        }

        return loc;
    }

    private Node remove(Node loc, int key ){
        if (loc == null)
            return loc;
        else if (loc.key == key) { // target Node found
            // Check if it is leaf node
            if (loc.left == null && loc.right == null) {
                return null;
            }
            // if it has only left child.
            if (loc.left != null && loc.right == null) {
                return loc.left;
            }
            //if it has only right child.
            if (loc.left == null && loc.right != null) {
                return loc.right;
            }
            // if it has both child
            if (loc.left != null && loc.right != null) {
                Node leftMaxNode = getMaximumKeyNode(loc.left);
                loc.key = leftMaxNode.key;
                loc.data = leftMaxNode.data;
                loc.left = remove(loc.left,leftMaxNode.key);
                return loc;
            }
        }

        else if (key < loc.key) {
            loc.left = remove(loc.left, key);
            setSize(loc);
            setHeight(loc);
        }
        else {
            loc.right = remove(loc.right, key);
            setSize(loc);
            setHeight(loc);
        }
        int balanceFactor = getBalance(loc);

        if (balanceFactor > 1) {
            switch (getBalance(loc.left)) {
                case 0:
                case 1: {
                    return rightRotation(loc);
                }
                case -1: {
                    loc.left = leftRotation(loc.left);
                    return rightRotation(loc);
                }
            }
        }
        else if (balanceFactor < -1) {
            switch (getBalance(loc.right)) {
                case 0:
                case 1: {
                    leftRotation(loc);
                }
                case -1: {
                    loc.right = rightRotation(loc.right);
                    return leftRotation(loc);
                }
            }
        }

        return loc;
    }

    private int search(Node loc , int key) {
        if (loc == null)
            return -1;
        else if (key == loc.key)
            return loc.data;
        else if (key < loc.key)
            return search(loc.left,key);
        else if (key > loc.key)
            return search(loc.right,key);
        return -1;
    }
    private void inorder(Node node) {
        if (node == null)
            return;
        inorder(node.left);
        System.out.println(node);
        inorder(node.right);
    }

    private void preorder(Node node) {
        if (node == null)
            return;
        System.out.println(node);
        preorder(node.left);
        preorder(node.right);
    }

    private void postorder(Node node) {
        if (node == null)
            return;
        postorder(node.left);
        postorder(node.right);
        System.out.println(node);
    }

    /**
     * inserts the key/value pair into the tree.
     * @param key unique key that identifies the corresponding value.
     * @param data value corresponding to data key.
     * */
    public void insert(int key , int data) {
        if (root != null)
            root = insert(root,key,data);
        else
            root = new Node(key,data);
    }

    /**
     * Prints the inorder traversal view of the tree.
     * */
    public void inorderTraversal() {
        inorder(root);
    }
    /**
     * Prints the preorder traversal view of the tree.
     * */
    public void preoderTraversal(){
        preorder(root);
    }
    /**
     * Prints the postorder traversal view of the tree.
     * */
    public  void postorderTraversal() {
        postorder(root);
    }
    /**
     * return
     * */
    public int getTreeHeight() {
        if (root != null)
            return root.height;
        else
            return 0;
    }

    /**
     * returns existing total number of key/value pairs in AVL Tree
     * @return size of tree
     * */
    public int getTreeSize() {
        if (root != null)
            return root.size;
        else
            return 0;
    }

    /**
     * removes the key/value pair that is specified by the key.
     * @param key key of the key/value pair.
     * */
    public void remove(int key) {
        if (root != null)
            root = remove(root,key);
    }
    /**
     * returns the corresponding value to the key given in parameter.
     * @param key key of the key/value pair.
     * @return value corresponding to the given key
     * */
    public int get(int key) {
        if (root != null)
            return search(root,key);
        return -1;
    }

}

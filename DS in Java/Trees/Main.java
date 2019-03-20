import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {



    public static void main(String[] args) {
        int[] keys = {45, 39, 56, 12, 34, 78, 32, 10, 89, 54, 67, 81};
        Node root = BST.createBST(keys);
        TopView.topviewleftright(root);
    }
}
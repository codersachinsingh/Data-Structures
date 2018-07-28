package datastructurs.trie;

import java.util.*;
/**
 * Trie is an efficient information re<b>Trie</b>val data structure. Using Trie, search complexities can be brought
 * to optimal limit (key length).
 * @author Sachin Singh
 * @version v1.0
 *
 * */
public class Trie {
    /**
     * root is a reference to top most node of the Trie tree.
     * */
    private TrieNode root;
    private int _size;
    private class TrieNode {
        Map<Character,TrieNode> childrens = new TreeMap<>();
        TrieNode parent;
        boolean isEnd;
    }
    private class StringTrieNode {
        TrieNode node;
        StringBuilder stringBuilder;
        StringTrieNode(TrieNode node , StringBuilder builder) {
            this.node = node;
            this.stringBuilder = builder;
        }
    }
    /**
     * Constructs a Trie.
     * */
    public Trie() {
        root = new TrieNode();
        _size = 0;
    }

    /**
     * Constructs a Trie with Given String array
     * */
    public Trie(String[] strings) {
        root = new TrieNode();
        _size = 0;
        for (String s : strings)
            insert(s);
    }
    /**
     * Inserts a String into Trie. if String already exist it will be ignored.
     * */
    public void insert(String word) {
        int len = word.length();
        TrieNode current = root;
        for (int i = 0 ; i < len ; i++) {
            char ch = word.charAt(i);
            if (current.childrens.containsKey(ch))
                current = current.childrens.get(ch);
            else {
                TrieNode node = new TrieNode();
                node.parent = current;
                current.childrens.put(ch,node);
                current = current.childrens.get(ch);
            }
        }
        if (!current.isEnd) // prevent increase for duplicate string.
            _size++;
        current.isEnd = true;
    }

    /**
     * Inserts many strings at once into Trie
     * */
    public void insert(String[] words) {
        for (String word : words)
            insert(word);
    }

    /**
     * Returns list of all the strings that best matches with given prefix.
     * */
    public List<String> autoCompleteWords(String prefix) {
        List<String> list = new ArrayList<>();
        TrieNode current = root;
        int prefixLength = prefix.length();
        for (int i = 0 ; i < prefixLength ; i++) {
            char ch = prefix.charAt(i);
            if (current.childrens.containsKey(ch))
                current = current.childrens.get(ch);
            else
                return list;
        }
        if (current.isEnd)
            list.add(prefix);

        StringBuilder stringBuilder = new StringBuilder(prefix);
        Stack<StringTrieNode> stack = new Stack<>();
        StringTrieNode ptr = new StringTrieNode(current,stringBuilder);
        while(!ptr.node.childrens.isEmpty() || !stack.isEmpty()) {
            if (ptr.node.childrens.isEmpty()) {
                ptr = stack.pop();
            }
            else if (ptr.node.childrens.size() == 1) {
                Iterator<Character> iterator = ptr.node.childrens.keySet().iterator();
                char ch = iterator.next();
                ptr.stringBuilder.append(ch);
                ptr.node = ptr.node.childrens.get(ch);
                if(ptr.node.isEnd)
                    list.add(ptr.stringBuilder.toString());
            }
            else {
                for (Character ch : ptr.node.childrens.keySet()) {
                    TrieNode n = ptr.node.childrens.get(ch);
                    StringBuilder sb = new StringBuilder(ptr.stringBuilder);
                    sb.append(ch);
                    if (n.childrens.isEmpty() && n.isEnd)
                        list.add(sb.toString());
                    else if (n.isEnd) {
                        list.add(sb.toString());
                        StringTrieNode trieNode1 = new StringTrieNode(n, sb);
                        stack.push(trieNode1);
                    } else {
                        StringTrieNode trieNode1 = new StringTrieNode(n, sb);
                        stack.push(trieNode1);
                    }
                }
                ptr = stack.pop();
            }
        }

        return list;
    }

    /**
     * Removes the given string from the trie. if it does not exist nothing would happened.
     * */
    public void remove(String word) {
        TrieNode current = root;
        for (int i = 0 ; i < word.length() ; i++) {
            char ch = word.charAt(i);
            if (current.childrens.containsKey(ch))
                current = current.childrens.get(ch);
            else
                return;
        }

        if (current.childrens.size() > 0) {
            current.isEnd = false;
            _size--;
            return;
        }


        boolean flag = true;
        int index = word.length()-1;
        while (flag) {
            current = current.parent;
            if (!current.isEnd && current.childrens.size() < 2) {
                char ch = word.charAt(index--);
                current.childrens.remove(ch);
            }
            if (!current.isEnd && current.childrens.size() > 1) {
                char ch = word.charAt(index--);
                current.childrens.remove(ch);
                flag = false;
                _size--;
            }
            else if (current.isEnd) {
                char ch = word.charAt(index--);
                current.childrens.remove(ch);
                flag = false;
                _size--;
            }


        }
    }

    /**
     * Returns the total number of strings exist in the trie.
     * */
    public int size() {
        return  _size;
    }

    /**
     * Removes all the given strings from trie if they exits.
     * */
    public void remove(String[] words) {
        for (String s : words)
            remove(s);
    }

    /**
     * Returns a list of all strings that exist in trie.
     * */
    public List<String> getAllStrings() {
        List<String> list = new ArrayList<>();
        for (Character ch : root.childrens.keySet()) {
            List<String> l = autoCompleteWords(ch.toString());
            list.addAll(l);
        }
        return list;
    }

    /**
     * Returns true if given string exits in trie. otherwise false.
     * */
    public boolean contains(String word) {
        int len = word.length();
        TrieNode current = root;
        for (int i = 0 ; i < len ; i++) {
            char ch = word.charAt(i);
            if (current.childrens.containsKey(ch))
                current = current.childrens.get(ch);
            else
                return false;
        }
        if (current.isEnd)
            return true;
        return false;
    }

}


package datastructures.patterns;

import java.util.HashMap;
import java.util.Map;

public class BoyerMoore {
    public  int patternMatch(String text , String pattern) {
        return patternMatch(text,pattern,true);
    }
    public int patternMatch(String text , String pattern , boolean caseSensitivity) {
        int n = text.length();
        int m = pattern.length();
        // make mismatch table for pattern.
        Map<Character,Integer> mismatchtable = new HashMap<>();
        for (int i = 0 ; i < m ; i++) {
            Character ch = pattern.charAt(i);
            int x = Math.max(1,m-i-1);
            mismatchtable.put(ch,x);
        }

        int numOfSkips;
        for (int i = 0 ; i < n-m ; i+=numOfSkips) {
            numOfSkips = 0;

            for (int j = m-1 ; j >= 0;j-- ) {
                char ch1 = text.charAt(i+j);
                char ch2 = pattern.charAt(j);
                if (!caseSensitivity) {
                    ch1 = Character.toUpperCase(ch1);
                    ch2 = Character.toUpperCase(ch2);
                }
                if (ch1 != ch2) {
                    char ch = text.charAt(i+j);
                    if (mismatchtable.containsKey(ch)) {
                        numOfSkips = mismatchtable.get(ch);
                        break;
                    }
                    else
                        numOfSkips = m;
                }
            }
            if (numOfSkips == 0)
                return i;
        }
        return -1;
    }
}
class Solution {
    List<String> ans;
    static String[] map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private String getCharsByNum(int num) {
        return map[num - 2];
    }

    public List<String> letterCombinations(String digits) {
        ans = new ArrayList<>();
        if ("".equals(digits)) {
            return ans;
        }
        dfs(0, new StringBuilder(), digits);
        return ans;
    }

    void dfs(int pos, StringBuilder cur, String digits) {
        if (pos == digits.length()) {
            ans.add(cur.toString());
            return;
        }
        for (char c : getCharsByNum(digits.charAt(pos) - '0').toCharArray()) {
            cur.append(c);
            dfs(pos + 1, cur, digits);
            cur.deleteCharAt(pos);
        }
    }
}
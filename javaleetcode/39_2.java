class Solution {
    List<List<Integer>> res;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        res = new ArrayList<>();
        dfs(target, new ArrayList<>(), candidates, 0);
        return res;
    }

    private void dfs(int val, List<Integer> cur, int[] candidates, int idx) {
        if (idx == candidates.length) {
            return;
        }
        if (val == 0) {
            res.add(new ArrayList(cur));
            return;    
        }

        dfs(val, cur, candidates, idx + 1);
        int candidate = candidates[idx];
        if (val >= candidate) {
            cur.add(candidate);
            dfs(val - candidate, cur, candidates, idx);
            cur.remove(cur.size() - 1);
        }
    }
}
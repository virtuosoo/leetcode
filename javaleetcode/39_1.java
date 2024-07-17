class Solution {
    List<List<Integer>> res;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        res = new ArrayList<>();
        dfs(target, new ArrayList<>(), candidates, 0);
        return res;
    }

    private void dfs(int val, List<Integer> cur, int[] candidates, int start) {
        if (val == 0) {
            res.add(new ArrayList(cur));
            return;    
        }
        for (int i = start; i < candidates.length; ++i) {
            int candidate = candidates[i];
            if (val >= candidate) {
                cur.add(candidate);
                dfs(val - candidate, cur, candidates, i);
                cur.remove(cur.size() - 1);
            }
        }
    }
}
class Solution {
    private List<List<Integer> > res;
    public List<List<Integer>> subsets(int[] nums) {
        res = new ArrayList<>();
        dfs(0, nums.length, new ArrayList<>(), nums);
        return res;
    }

    private void dfs(int pos, int n, List<Integer> cur, int[] nums) {  
        if (pos == n) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        dfs(pos + 1, n, cur, nums);
        cur.add(nums[pos]);
        dfs(pos + 1, n, cur, nums);
        cur.remove(cur.size() - 1);
    } 
}
class Solution {

    public int canCompleteCircuit(int[] gas, int[] cost) {
        int len = gas.length;

        int totalGas = 0, startIdx = 0, currGas = 0; 

        for(int i = 0; i < len; i++){
            int diff = gas[i] - cost[i];
            totalGas += diff;
            currGas += diff;

            if(currGas < 0) {
                startIdx = i + 1;
                currGas = 0;
            }
        }

        return totalGas >= 0 ? startIdx : -1;
    }
}
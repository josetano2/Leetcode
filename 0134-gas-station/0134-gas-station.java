class Solution {

    public int canCompleteCircuit(int[] gas, int[] cost) {
        int len = gas.length;

        int startingIdx = -1;
        int idx = -1;
        boolean isLooped = false;
        int lastGas = gas[0];

        if(len == 1) {
            return gas[0] - cost[0] >= 0 ? 0 : -1;
        }

        for(int i = 0; i < len; i++) {
            if(gas[i] - cost[i] > 0) {
                startingIdx = i;
                lastGas = gas[i];
                idx = i;
                break;
            }
        }

        if(startingIdx == -1) return -1;
 
        do {
            if (startingIdx == idx && isLooped) {
                break;
            }

            lastGas = lastGas - cost[idx];

            if (lastGas >= 0) {
                lastGas += +gas[(1 + idx) % len];
                idx = (1 + idx) % len;
                if (startingIdx == idx) {
                    isLooped = true;
                }
            }
            else {
                startingIdx++;
                idx = startingIdx;
                lastGas = gas[idx % len];
            }

        } while (startingIdx < len);

        return isLooped ? startingIdx : -1;
    }
}
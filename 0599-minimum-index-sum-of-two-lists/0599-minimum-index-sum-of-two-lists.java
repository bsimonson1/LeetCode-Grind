class Solution {
    // public String[] addElement(String[] same, String i) {
    //     String[] newArray = Arrays.copyOf(same, same.length + 1);
    //     newArray[newArray.length - 1] = i;
    //     return newArray;
    // }
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> mp1 = new HashMap<>(); 
        int lowest = Integer.MAX_VALUE;
        ArrayList<String> same = new ArrayList<>();
        for (int i = 0; i < list1.length; i++)
        {
            mp1.put(list1[i], i);
        }
        for (int i = 0; i < list2.length; i++)
        {
            if (mp1.containsKey(list2[i]) && (mp1.get(list2[i]) + i) < lowest)
            {
                lowest = mp1.get(list2[i]) + i;
                same.clear();
                same.add(list2[i]);
                // same = addElement(same, list2[i]); 
            }
            else if (mp1.containsKey(list2[i]) && (mp1.get(list2[i]) + i) == lowest)
            {
                //same = addElement(same, list2[i]);
                same.add(list2[i]);
            }
        }
        int n = same.size();
        String[] ret = new String[n];
        for (int i = 0; i < n; i++)
        {
            ret[i] = same.get(i);
        }
        return ret;
    }
}
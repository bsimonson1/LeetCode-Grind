class Solution {
    public String removeOccurrences(String s, String part) {
        while (s.indexOf(part) != -1 && s.length() >= part.length())
        {
            s = s.replaceFirst(part, "");
            //s = removeOccurrences(s, part);
        }
        return s;
    }
}
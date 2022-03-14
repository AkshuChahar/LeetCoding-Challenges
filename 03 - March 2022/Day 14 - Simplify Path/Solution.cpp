class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        // Add '/' at the end if it is not there.
        if (path[n-1] != '/') {
            path += "/";
            n++;
        }

        // Initialise a stack to store the directories.
        stack<string> s;
        string ans = "";
        string temp = "";

        // Traverse the 'path' from index 1.
        int i = 1;
        while (i < n) {
            // If '/' is encountered.
            if (path[i] == '/') {
                // If 'temp' is empty or ".", we ignore it.
                if (temp == "" || temp == ".") {}
                // If temp becomes "..", pop the stack element.
                else if (temp == "..") {
                    if (!s.empty())
                        s.pop();
                }
                // Else push 'temp' to the stack.
                else
                    s.push(temp);
                // Reset 'temp';
                temp = "";
            }
            // Else add the current element to 'temp'.
            else
                temp.push_back(path[i]);
            i++;
        }

        // Add all the stack elements to 'ans'.
        while (!s.empty()) {
            ans = '/' + s.top() + ans;
            s.pop();
        }

        // If no directory is present, return "/".
        if (ans.length() == 0)
            ans = "/";

        return ans;
    }
};
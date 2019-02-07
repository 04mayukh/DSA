#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


bool callback(const pair <long long, pair <char,long long> > &a, const pair <long long, pair <char,long long> > &b){
    if(a.first<b.first)
    return true;
    if(a.first==b.first){
        return (a.second.first < b.second.first);
    }
    return false;
}

long long maximumPeople(vector<long> p, vector<long> x, vector<long> y, vector<long> r) {

    vector< pair <long long, pair <char,long long> > > pts;

    for(long i=0;i<x.size();i++)
    pts.push_back(make_pair(x[i],make_pair('p',p[i])));

    for(long long i=0;i<y.size();i++){
        pts.push_back(make_pair(y[i]-r[i],make_pair('l',y[i]+r[i])));
        pts.push_back(make_pair(y[i]+r[i],make_pair('r',0)));
    }

    long long segment = 0;
    long long max = 0;
    long long temp = 0;
    long long w = 0;

    sort(pts.begin(),pts.end(), callback);
    vector<long> a;
    int flag = 0;

    for(long long i=0;i<pts.size();i++){
        cout<<pts[i].first<<" "<<pts[i].second.first<<"    ";
        if(pts[i].second.first == 'p'){

            if(segment == 0 ){
                w += pts[i].second.second;
            }

            if(segment==1)
            {
                temp += pts[i].second.second;  
            }

        }
        if(pts[i].second.first == 'l' ){
            
            segment++;
            if(flag!=0){
                if(a.back() <= pts[i].second.second){
                    a.push_back(pts[i].second.second);
                    cout<<" h "<<pts[i].second.second<<" h ";
                }
            }

            if(flag==0){
                a.push_back(pts[i].second.second);
                flag++;
            }


        }
        if(pts[i].second.first == 'r' ){
            segment--;
            cout<<" h "<<a[0]<<"  "<<pts[i].first<<" h ";
            if(a[0] == pts[i].first){
                a.erase(a.begin());
                if(temp>max)
                max = temp;
                temp = 0;
            }
            //cout<<" h "<<a[0]<<"  "<<pts[i].first<<" h ";
        }


        cout<<segment<<" "<<temp<<endl;
    }
    

    return w+max;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<long> p(n);

    for (int i = 0; i < n; i++) {
        long p_item = stol(p_temp[i]);

        p[i] = p_item;
    }

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<long> x(n);

    for (int i = 0; i < n; i++) {
        long x_item = stol(x_temp[i]);

        x[i] = x_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string y_temp_temp;
    getline(cin, y_temp_temp);

    vector<string> y_temp = split_string(y_temp_temp);

    vector<long> y(m);

    for (int i = 0; i < m; i++) {
        long y_item = stol(y_temp[i]);

        y[i] = y_item;
    }

    string r_temp_temp;
    getline(cin, r_temp_temp);

    vector<string> r_temp = split_string(r_temp_temp);

    vector<long> r(m);

    for (int i = 0; i < m; i++) {
        long r_item = stol(r_temp[i]);

        r[i] = r_item;
    }

    long long result = maximumPeople(p, x, y, r);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

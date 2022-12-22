// Practical 10

#include<bits/stdc++.h>
using namespace std;
class NaiveBayesClassifier{
private:
    unordered_map<int,double> classes;
    unordered_map<int, unordered_map<int, double>> attributesPerClass;
public:
    NaiveBayesClassifier(vector<vector<int>> &data, int DimSize)
    {
        for(auto entry:data){
            if(classes.find(entry[0])==classes.end())
            {
                classes[entry[0]]=1;
                unordered_map<int, double> pxc;
                attributesPerClass[entry[0]] = pxc;

            }
            else{
                classes[entry[0]]+=1;

            }
            for(int k=1;k<DimSize;k++){
                if(attributesPerClass[entry[0]].find(entry[k])== attributesPerClass[entry[0]].end())
                {
                    attributesPerClass[entry[0]][entry[k]]=1;
                    }
 else
 {

     attributesPerClass[entry[0]][entry[k]] +=1;

 }
 }
 }
 for(auto seg: attributesPerClass)
 {

     if(seg.first==0)
     {

         cout<<"--- Class Apple"<<"---"<<endl;
     }
     if(seg.first==1)
     {
         cout<<" --- Class PineApple"<<"---"<<endl;
     }
     if(seg.first==2)
     {
         cout<<"--- Class Cherry"<<"---"<< endl;
     }
     for(auto entry: seg.second)
     {

         entry.second /= classes[seg.first];
         cout<<"Attribute P(A="<<entry.first<<"| B="<<seg.first <<")="<< entry.second<< endl;
     }
     classes[seg.first]/= data.size();
     cout<<"Class P(B="<<seg.first<< ")="<<classes[seg.first]<<"\n\n";
 }
 }
int predict(vector<int> attributes)
{
int maxcid = -1;
double maxp = 0;
for(auto cls :classes)
{
double pCx=cls.second;
for(int i=0;attributes.size();i++){
pCx*=attributesPerClass[cls.first][attributes[i]];
}
if(pCx>maxp){
maxp=pCx;
maxcid=cls.first;
}
}
cout<<"Predict Class:\t"<<maxcid<<"===>P(A|B) = "<<maxp<<endl;
return maxcid;
}
};
void populateData(vector<vector<int>> &data,unordered_map<string,int>&classmap,unordered_map<string,int>&attrimap,string c , string a1,string a2,int K)
{
vector<int> apair={classmap[c],attrimap[a1],attrimap[a2]};
vector<vector<int>> newarr(K,apair);
data.insert(data.end(),newarr.begin(),newarr.end());
}
int main() {
    unordered_map<string, int> classmap = {{"apple",0}, {"pineapple", 1}, {"cherry", 2}};
    unordered_map<string, int> attrimap = {{"red", 0}, {"green", 1}, {"yellow", 2},

    {"round", 10},{"oval", 11}, {"heart", 2}};

    vector<vector<int>> data;
    populateData(data, classmap,attrimap, "apple", "green", "round", 20);
    populateData(data, classmap,attrimap, "apple", "red", "round", 50);
    populateData(data, classmap,attrimap, "apple", "yellow", "round", 10);
    populateData(data, classmap,attrimap, "apple", "red", "oval", 5);
    populateData(data, classmap,attrimap, "apple", "red", "heart", 5);
    populateData(data, classmap,attrimap, "pineapple", "green", "oval", 30);
    populateData(data, classmap,attrimap, "pineapple", "yellow", "oval", 70);
    populateData(data, classmap,attrimap, "pineapple", "green", "round", 5);
    populateData(data, classmap,attrimap, "pineapple", "yellow", "round", 5);
    populateData(data, classmap,attrimap, "cherry", "yellow", "heart", 50);
    populateData(data, classmap,attrimap, "cherry", "red", "heart", 70);
    populateData(data, classmap,attrimap, "cherry", "yellow", "round", 5);
    random_shuffle(data.begin(),data.end());

NaiveBayesClassifier mymodel(data, 2);

int  cls = mymodel.predict({attrimap["red"],attrimap["round"]});
if(cls==0)
{
cout<<"Predicted class:\tApple"<<endl;
}
if(cls==1)
{
cout<<"Predicted class:\tPineapple"<<endl;
}
if(cls==2)
{
cout<<"Predicted class:\tCherry"<<endl;
}
return 0;
}

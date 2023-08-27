#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Page
{
	int idx;
	int basic, link;
	double score;
};

bool cmp(Page a, Page b)
{
	if (a.score == b.score) return a.idx < b.idx;
	return a.score > b.score;
}
int solution(string word, vector<string> pages) {
	int wSize = word.size();
	int pSize = pages.size();
	map<string, int> pageHash;
	vector<Page> pageList;
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	
	for (int i = 0; i < pSize; i++){
		string &s = pages[i];
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		
		//meta(url)===========================================//
		int posMid = 0, posL = 0, posR = 0;
		while (posMid <= posL){
			posL = s.find("<meta", posL + 1);
			posR = s.find(">", posL);
			posMid = s.rfind("https://", posR);
		}
		posR = s.find("\"", posMid);
		string url = s.substr(posMid, posR - posMid);

		//body(검색어)=======================================//
		posL = s.find("<body>", posR);
		int basic = 0;
		for (int start = posL; ; ){
			start = s.find(word, start + 1);
			if (start == string::npos) break;
			else{
				//양옆이 문자면 안됨
				if (!isalpha(s[start - 1]) && !isalpha(s[start + wSize])){
					basic++;
					start += wSize;
				}
			}
		}
		
		//a href(link)=========================================//
		int link = 0;
		for (int start = posL; ;){
			start = s.find("<a href", start + 1);
			if (start == string::npos) break;
			else link++;
		}
		pageHash[url] = i;
		pageList.push_back({i,basic,link,(double)basic});
	}

	//매칭점수 계산
	for (int i = 0; i < pSize; i++)
	{
		string &s = pages[i];
		for (int posL = 0, posR = 0; ; )
		{
			posL = s.find("<a href", posR);
			if (posL == string::npos) break;
			else
			{
				posL = s.find("https://", posL);
				posR = s.find("\"", posL);
				string linkUrl = s.substr(posL, posR - posL);
				map<string, int>::iterator it = pageHash.find(linkUrl);
				if (it != pageHash.end()){
					pageList[it->second].score +=
						(double)pageList[i].basic / (double)pageList[i].link;
				}
			}
		}
	}

	sort(pageList.begin(), pageList.end(), cmp);
	return pageList.begin()->idx;
}
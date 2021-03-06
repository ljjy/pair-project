#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<ctype.h>
#include<string>
#include<string.h>
#include<fstream>
#include<vector>
#include<queue> 
#include"iomanip"
using namespace std;

#define ALPHABET_SIZE 69
vector<string> v_Lines;
vector<string> v_Words;
vector<string> v_FenGe;
vector<string>::iterator iter, iter1, iter2;
string str_Words[100], str_Phrases[100];
int ans_Words[100], ans_Phrases[100];
int rows = 0, ct = 0, d = 0, a = 0, e = 0, b = 0, word_Num = 0;
struct FrequentWord
{
	string word;
	int weight;
	friend bool operator < (FrequentWord a, FrequentWord b)
	{
		if (a.weight == b.weight)
			return a.word<b.word;
		else
			return a.weight > b.weight;
	}
}fqtWord;
priority_queue<FrequentWord> q_Word, q_Phrase;

queue<string> q1, q2;
typedef struct trie_node
{
	int count_Title;
	int count_Abstract;
	int weight;
	string word;
	trie_node *children[ALPHABET_SIZE];
}*trie;

trie root_Words;
trie root_Phrases;
trie_node* create_trie_node()
{
	trie_node* pNode = new trie_node();
	pNode->count_Title = 0;
	pNode->count_Abstract = 0;
	pNode->weight = 0;
	for (int i = 0; i<ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
	return pNode;
}

void trie_insert(trie root, string key, int flag, int parameter = 0)
{
	trie_node* node = root;
	string p = key;
	string w;
	for (int i = 0;i<p.length();i++)
	{
		if (p[i] >= 'A' && p[i] <= 'Z')
		{
			p[i] += 32;
		}
		if (p[i] >= '0' && p[i] <= '9' && node->children[p[i] - '0'] == NULL)
		{
			node->children[p[i] - '0'] = create_trie_node();
		}
		else if (p[i] >= 'a' && p[i] <= 'z' && node->children[p[i] - 'a' + 10] == NULL)
		{
			node->children[p[i] - 'a' + 10] = create_trie_node();
		}
		else if (p[i] == '-' && node->children[36] == NULL)
		{
			node->children[36] = create_trie_node();
		}
		else if (p[i] == ' ' && node->children[37] == NULL)
		{
			node->children[37] = create_trie_node();
		}
		else if (p[i] == '.' && node->children[38] == NULL)
		{
			node->children[38] = create_trie_node();
		}
		else if (p[i] == ',' && node->children[39] == NULL)
		{
			node->children[39] = create_trie_node();
		}
		else if (p[i] == '?' && node->children[40] == NULL)
		{
			node->children[40] = create_trie_node();
		}
		else if (p[i] == '!' && node->children[41] == NULL)
		{
			node->children[41] = create_trie_node();
		}
		else if (p[i] == '(' && node->children[42] == NULL)
		{
			node->children[42] = create_trie_node();
		}
		else if (p[i] == ')' && node->children[43] == NULL)
		{
			node->children[43] = create_trie_node();
		}
		else if (p[i] == '"' && node->children[44] == NULL)
		{
			node->children[44] = create_trie_node();
		}
		else if (p[i] == '/' && node->children[45] == NULL)
		{
			node->children[45] = create_trie_node();
		}
		else if (p[i] == '{' && node->children[46] == NULL)
		{
			node->children[46] = create_trie_node();
		}
		else if (p[i] == '}' && node->children[47] == NULL)
		{
			node->children[47] = create_trie_node();
		}
		else if (p[i] == '$' && node->children[48] == NULL)
		{
			node->children[48] = create_trie_node();
		}
		else if (p[i] == '\\' && node->children[49] == NULL)
		{
			node->children[49] = create_trie_node();
		}
		else if (p[i] == '|' && node->children[50] == NULL)
		{
			node->children[50] = create_trie_node();
		}
		else if (p[i] == '[' && node->children[51] == NULL)
		{
			node->children[51] = create_trie_node();
		}
		else if (p[i] == ']' && node->children[52] == NULL)
		{
			node->children[52] = create_trie_node();
		}
		else if (p[i] == '+' && node->children[53] == NULL)
		{
			node->children[53] = create_trie_node();
		}
		else if (p[i] == '*' && node->children[54] == NULL)
		{
			node->children[54] = create_trie_node();
		}
		else if (p[i] == '%' && node->children[55] == NULL)
		{
			node->children[55] = create_trie_node();
		}
		else if (p[i] == '^' && node->children[56] == NULL)
		{
			node->children[56] = create_trie_node();
		}
		else if (p[i] == '&' && node->children[57] == NULL)
		{
			node->children[57] = create_trie_node();
		}
		else if (p[i] == '=' && node->children[58] == NULL)
		{
			node->children[58] = create_trie_node();
		}
		else if (p[i] == '~' && node->children[59] == NULL)
		{
			node->children[59] = create_trie_node();
		}
		else if (p[i] == '\'' && node->children[60] == NULL)
		{
			node->children[60] = create_trie_node();
		}
		else if (p[i] == '@' && node->children[61] == NULL)
		{
			node->children[61] = create_trie_node();
		}
		else if (p[i] == '#' && node->children[62] == NULL)
		{
			node->children[62] = create_trie_node();
		}
		else if (p[i] == '_' && node->children[63] == NULL)
		{
			node->children[63] = create_trie_node();
		}
		else if (p[i] == '`' && node->children[64] == NULL)
		{
			node->children[64] = create_trie_node();
		}
		else if (p[i] == '<' && node->children[65] == NULL)
		{
			node->children[65] = create_trie_node();
		}
		else if (p[i] == '>' && node->children[66] == NULL)
		{
			node->children[66] = create_trie_node();
		}
		else if (p[i] == ':' && node->children[67] == NULL)
		{
			node->children[67] = create_trie_node();
		}
		else if (p[i] == ';' && node->children[68] == NULL)
		{
			node->children[68] = create_trie_node();
		}
		if (p[i] >= '0' && p[i] <= '9')
			node = node->children[p[i] - '0'];
		else if (p[i] >= 'a' && p[i] <= 'z')
			node = node->children[p[i] - 'a' + 10];
		else if (p[i] == '-')
			node = node->children[36];
		else if (p[i] == ' ')
			node = node->children[37];
		else if (p[i] == '.')
		{
			node = node->children[38];
		}
		else if (p[i] == ',')
		{
			node = node->children[39];
		}
		else if (p[i] == '?')
		{
			node = node->children[40];
		}
		else if (p[i] == '!')
		{
			node = node->children[41];
		}
		else if (p[i] == '(')
		{
			node = node->children[42];
		}
		else if (p[i] == ')')
		{
			node = node->children[43];
		}
		else if (p[i] == '"')
		{
			node = node->children[44];
		}
		else if (p[i] == '/')
		{
			node = node->children[45];
		}
		else if (p[i] == '{')
		{
			node = node->children[46];
		}
		else if (p[i] == '}')
		{
			node = node->children[47];
		}
		else if (p[i] == '$')
		{
			node = node->children[48];
		}
		else if (p[i] == '\\')
		{
			node = node->children[49];
		}
		else if (p[i] == '|')
		{
			node = node->children[50];
		}
		else if (p[i] == '[')
		{
			node = node->children[51];
		}
		else if (p[i] == ']')
		{
			node = node->children[52];
		}
		else if (p[i] == '+' )
		{
			node = node->children[53];
		}
		else if (p[i] == '*' )
		{
			node = node->children[54];
		}
		else if (p[i] == '%')
		{
			node = node->children[55];
		}
		else if (p[i] == '^')
		{
			node = node->children[56];
		}
		else if (p[i] == '&')
		{
			node = node->children[57];
		}
		else if (p[i] == '=')
		{
			node = node->children[58];
		}
		else if (p[i] == '~')
		{
			node = node->children[59];
		}
		else if (p[i] == '\'')
		{
			node = node->children[60];
		}
		else if (p[i] == '@')
		{
			node = node->children[61];
		}
		else if (p[i] == '#' )
		{
			node = node->children[62];
		}
		else if (p[i] == '_')
		{
			node = node->children[63];
		}
		else if (p[i] == '`')
		{
			node = node->children[64];
		}
		else if (p[i] == '<')
		{
			node = node->children[65];
		}
		else if (p[i] == '>')
		{
			node = node->children[66];
		}
		else if (p[i] == ':')
		{
			node = node->children[67];
		}
		else if (p[i] == ';')
		{
			node = node->children[68];
		}
		w += p[i];
	}
	if (flag == 0)
	{
		//cout << "flag = 0     "<<parameter << endl;
		node->count_Title += 1;
		if (parameter == 0)
			node->weight += 1;
		else
			node->weight += 10;
	}
	else
	{
		//cout << "flag = 1     " << parameter << endl;
		node->count_Abstract += 1;
		node->weight += 1;

		//cout << "weigth: " << node->weight << endl;
	}
	node->word = w;
	//return node;
}
int trie_search(trie root, string key)
{
	string p = key;
	trie_node* node = root;
	int i = 0;
	while (i<p.length() && node != NULL)
	{
		if (p[i] >= 'A' && p[i] <= 'Z')
		{
			p[i] += 32;
		}
		if (p[i] >= '0' && p[i] <= '9')
			node = node->children[p[i] - '0'];
		else if (p[i] >= 'a' && p[i] <= 'z')
			node = node->children[p[i] - 'a' + 10];
		else if (p[i] == '-')
			node = node->children[36];
		i++;
	}

	if (node == NULL)
		return 0;
	else
		return node->count_Title + node->count_Abstract;
}

void triePreorderTraversal(trie root, int maxNumber)
{
	if (root == NULL)
		return;
	if (root->weight != 0)
	{
		fqtWord.weight = root->weight;

		fqtWord.word = root->word;
		if (q_Word.size()<maxNumber)
		{
			q_Word.push(fqtWord);
		}
		else
		{
			q_Word.push(fqtWord);
			q_Word.pop();
		}
	}
	for (int i = 0; i<ALPHABET_SIZE; i++)
	{
		triePreorderTraversal(root->children[i],maxNumber);
	}
}

int Initialize(string fileName)
{
	ifstream file;
	file.open(fileName.data());   //将文件流对象与文件连接起来 
	if (!file.is_open())
	{
		cout << "文件无法打开" << endl;
		return 0;
	}

	string temp;
	while (getline(file, temp))
	{
		//b++;
		//cout << b << "行：     " << endl;
		v_Lines.push_back(temp);
	}
	file.close();             
	//关闭文件输入流 			  
	/*
	ifstream file(fileName);
							  if (!file.is_open())
							  {
							  cout << "文件无法打开" << endl;
							  return 0;
							  }
							  string temp;
							  while (!file.eof() && file.peek() != EOF)
							  //while(!file.eof())
							  {
							  b++;
							  cout<<b<<"行：     "<<endl;
							  file.getline(text, 2000);
							  temp = text;
							  v_Lines.push_back(temp);
							  }
							  file.close();
							  b = 0;
							  */
}

int CharacterCount()
{
	string temp;
	int len, i, j, k;
	int r = 0;
	int sum = 0;
	for (iter = v_Lines.begin();iter != v_Lines.end();iter++)
	{
		temp = *iter;
		len = temp.length();
		if (len == 0)	continue;	//空行

		for (i = 0;i < len;i++)		//序号
		{
			if (!(temp[i] >= '0' && temp[i] <= '9'))
				break;
		}
		if (i == len)	continue;

		if (len >= 6 && temp[0] == 'T' && temp[1] == 'i' && temp[2] == 't' && temp[3] == 'l' && temp[4] == 'e' && temp[5] == ':'&& temp[6] == ' ')
		{
			len = len - 7;
			//cout<<"Title"<<a<<":     "<<len<<endl;
		}

		if (len >= 9 && temp[0] == 'A' && temp[1] == 'b' && temp[2] == 's' && temp[3] == 't' && temp[4] == 'r' && temp[5] == 'a' && temp[6] == 'c' && temp[7] == 't')
		{
			len = len - 10;
			//cout<<"Abstract"<<a<<":     "<<len<<endl;
			//a++;
		}

		sum += len;
		r++;
		//cout << sum << "  " << r << endl;
	}
	if (sum == 0)
		return 0;
	else
		return sum + r - 1;

}
int EffectiveLinesCount()
{
	int sum = 0;
	string temp;
	int flag, len, i, j;
	for (iter = v_Lines.begin();iter != v_Lines.end();iter++)
	{
		temp = *iter;
		len = temp.length();
		for (i = 0;i < len;i++)		//序号
		{
			if (temp[i] >= '0' && temp[i] <= '9')
				continue;
			else
				break;
		}
		//cout << "i" << i << endl;
		if (i == len)
		{
			continue;
		}


		for (int j = 0;j<len;j++)
		{
			if (temp[j] != ' ' && temp[j] != '\t' && temp[j] != '\n')
			{
				sum++;
				break;
			}
		}
	}
	return sum;
}

void PhraseOrWordCount(int maxLength, int parameter = 0)	
{
	string temp;
	int len, i, j, k, flag = 0;
	for (iter2 = v_Lines.begin();iter2 != v_Lines.end();iter2++)
	{
		temp = *iter2;
		len = temp.length();
		if (len == 0)	continue;

		j = 0;
		for (i = 0;i < len;i++)		//序号
		{
			if (!(temp[i] >= '0' && temp[i] <= '9'))
				break;
		}
		if (i == len)
		{
			continue;
		}

		if (len >= 6 && temp[0] == 'T' && temp[1] == 'i' && temp[2] == 't' && temp[3] == 'l' && temp[4] == 'e' && temp[5] == ':'&& temp[6] == ' ')
		{
			j = 7;
			flag = 1;
		}

		if (len >= 9 && temp[0] == 'A' && temp[1] == 'b' && temp[2] == 's' && temp[3] == 't' && temp[4] == 'r' && temp[5] == 'a' && temp[6] == 'c' && temp[7] == 't')
		{
			j = 10;
			flag = 2;
		}

		for (j;j < len;)
		{
			//if (temp[j] == ' ')
			//{
				//cout << a <<"空格"<< endl;
				//a++;
			//}
			int m = j;

			if ((temp[j] >= 'A' && temp[j] <= 'Z') || (temp[j] >= 'a' && temp[j] <= 'z') || (temp[j] >= '0' && temp[j] <= '9'))
			{
				for (k = j + 1;k < len;k++)
				{
					if (!((temp[k] >= 'A' && temp[k] <= 'Z') || (temp[k] >= 'a' && temp[k] <= 'z') || (temp[k] >= '0' && temp[k] <= '9')))
					{
						v_Words.push_back(temp.substr(m, k - m));
						j = k;
						break;
					}
				}
				if (k == len)
				{
					v_Words.push_back(temp.substr(m, k - m));
					j = k;
				}
			}
			else
			{
				for (k = j + 1;k < len;k++)
				{
					if ((temp[k] >= 'A' && temp[k] <= 'Z') || (temp[k] >= 'a' && temp[k] <= 'z') || (temp[k] >= '0' && temp[k] <= '9'))
					{
						v_FenGe.push_back(temp.substr(m, k - m));
						j = k;
						break;
					}
				}

				if (k == len)
				{
					v_FenGe.push_back(temp.substr(m, k - m));
					j = k;
				}
			}
			//cout << temp.substr(m, k - m) << endl;;
		}
		//cout <<endl<< "################################################################" << endl;

		string s, w, t, fg, w1;
		//int sum = 0;
		//a = 0;
		while (!q1.empty())	q1.pop();
		while (!q2.empty())	q2.pop();
		for (iter = v_Words.begin(), iter1 = v_FenGe.begin();;)	//都用iter时 压入数据会导致iter失效
		{
			if (iter != v_Words.end())
				w = *iter;
			else
				w = ' ';
			if (iter1 != v_FenGe.end())
				w1 = *iter1;
			else
				w1 = ' ';
			q2.push(w1);
			if (w.length() >= 4 && isalpha(w[0]) && isalpha(w[1]) && isalpha(w[2]) && isalpha(w[3]))
			{
				word_Num++;
				//cout << "P单词" << a << ":  " << w << endl;
				//a++;
				q1.push(w);
				if (q1.size() == maxLength && maxLength != 0)
				{
					s.clear();
					for (i = 0;i < maxLength;i++)
					{
						t = q1.front();
						s += t;
						
						if (i == 0)
						{
							fg = q2.front();
							q2.pop();
							s += fg;
						}
						else if (i < maxLength - 1)
						{
							fg = q2.front();
							s += fg;
							q2.pop();
							q2.push(fg);
						}
						q1.pop();
						q1.push(t);
					}
					q1.pop();	
					//cout <<"词组"<<a<<":   "<< s << endl;
					//a++;
					if (flag == 1 )
					{
						trie_insert(root_Phrases, s, 0, parameter);
					}
					else
					{
						trie_insert(root_Phrases, s, 1, parameter);
					}
				}
				if (flag == 1 && maxLength == 0)
				{
					//cout <<root_Words<< "afdsfdsf:         " << w << endl;
					trie_insert(root_Words, w, 0, parameter);
				}
				else if (flag == 0 && maxLength == 0)
				{
					//cout << root_Words << "afdsfdsf:         " << w << endl;
					trie_insert(root_Words, w, 1, parameter);
				}
			}
			else
			{
				while (!q1.empty())	q1.pop();
				while (!q2.empty())	q2.pop();
			}
			if (iter != v_Words.end() && iter1 != v_FenGe.end())
			{
				//cout << *iter << *iter1;
				iter++;
				iter1++;
			}
			else if (iter != v_Words.end() && iter1 == v_FenGe.end())
			{
				//cout << *iter;
				iter++;
			}
			else if (iter == v_Words.end() && iter1 != v_FenGe.end())
			{
				//cout << *iter1;
				iter1++;
			}
			else
			{
				break;
			}
		}
		v_FenGe.clear();
		v_Words.clear();
		//cout << endl << "################################################################" << endl;
	}

}
void FrequentWordCount(int maxNumber)
{
	triePreorderTraversal(root_Words,maxNumber);

	while (!q_Word.empty())
	{
		fqtWord = q_Word.top();
		str_Words[d] = fqtWord.word;
		ans_Words[d] = fqtWord.weight;
		d++;
		q_Word.pop();
	}
	//return root;
}
void FrequentPhraseCount(int maxNumber)
{

	triePreorderTraversal(root_Phrases,maxNumber);

	while (!q_Word.empty())
	{
		fqtWord = q_Word.top();
		str_Phrases[e] = fqtWord.word;
		ans_Phrases[e] = fqtWord.weight;
		e++;
		q_Word.pop();
	}
	//cout << d <<"   "<<e<< endl;
		//return root;
}
int main(int argc, char* argv[])
{
	int flag1 = 0, flag2 = 0, t = 1;
	int parameter = 0, maxLength = 0, maxNumber = 10;
	string inFileName,outFileName;
	
	for (int i = 1;i < argc;i = i + 2)
	{
		string str = argv[i];
		string str1 = argv[i + 1];
		if (str == "-i")
		{
			inFileName = str1;
		}
		else if (str == "-o")
		{
			outFileName = str1;
		}
		else if (str == "-w")
		{
			parameter = str1[0] - '0';
		}
		else if (str == "-m")
		{
			flag1 = 1;
			t = 1;
			maxLength = 0;
			for (int i = str1.length()-1;i >= 0;i--)
			{
				maxLength += (str1[i] - '0')*t;
				t *= 10;
			}

			if (maxLength < 2 || maxLength>10)
			{
				cout << "词组长度应大于等于2且小于等于10" << endl;
				return 0;
			}
		}
		else if (str == "-n")
		{

			flag2 = 2;
			t = 1;
			maxNumber = 0;
			for (int i = str1.length() - 1;i >= 0;i--)
			{
				maxNumber += (str1[i] - '0')*t;
				t *= 10;
			}

			if (maxNumber < 0 || maxNumber>100)
			{
				cout << "输出词频的个数应大于等于0且小于等于100"<< endl;
				return 0;
			}
		}
		else
		{
			cout << "出现不符合规定的参数" << endl;
			return 0;
		}
	}

	
	root_Words = create_trie_node();
	root_Phrases = create_trie_node();
	Initialize(inFileName);
	int num = CharacterCount();
	PhraseOrWordCount(maxLength, parameter);	//当不出现-m时 maxNumber = 0,不启用词组统计，当maxNumber!=0 不启用单词统计

	ofstream out(outFileName);
	if (argv[1] == NULL)
	{
		cout << "输入为空" << endl;
		return 0;
	}
	out << "character: " << num << endl;
	out << "words: " << word_Num << endl;
	out << "lines: " << EffectiveLinesCount() << endl;

	//flag1 == 1 表示 使用词组统计代替单词统计	=0表示 单词统计
	//flag2 == 1 表示 限制最后的输出个数		=0表示 默认输出10个
	if (flag1 == 1 )
	{
		FrequentPhraseCount(maxNumber);
		for (int i = e - 1;i >= 0;i--)
		{
			if (out.is_open())
			{
				out << "<" << str_Phrases[i] << ">: " << ans_Phrases[i] << endl;
			}
		}
	}
	else
	{
		FrequentWordCount(maxNumber);
		for (int i = d - 1;i >= 0;i--)
		{
			if (out.is_open())
			{
				out << "<" << str_Words[i] << ">: " << ans_Words[i] << endl;
			}
		}
	}

	
	out.close();

	
	system("pause");
	
	
	return 0;
}
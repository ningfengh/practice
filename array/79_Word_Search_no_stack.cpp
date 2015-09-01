#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
string to_string(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

class Solution {
public:
	bool search(vector<vector<char> >& board,vector<vector<bool> >& occupy,string& word,int start,int i,int j)
	{
		int length = word.size();
		int m = board.size();    // number of rows
		int n = board[0].size();   // number of columns
		bool flag = false;
		
		cout<<"word="<<word<<endl;
		cout<<"i="<<i<<endl;
		cout<<"j="<<j<<endl;
		cout<<"start="<<start<<endl;
		if (start == length) 
		{
			cout<<"length=0"<<endl;
			return true;
		}
		else 
		{
			if (i>0 && occupy[i-1][j]==0 && board[i-1][j]==word[start]) // left
			{
				occupy[i-1][j]=1;
				flag = search(board,occupy,word,start+1,i-1,j);
				cout<<"return flag "<<flag<<endl;
				occupy[i-1][j]=0;
			}
			else if (i<m-1 && occupy[i+1][j]==0 && board[i+1][j]==word[start]) //right
			{
				occupy[i+1][j]=1;
				flag = search(board,occupy,word,start+1,i+1,j);
				cout<<"return flag "<<flag<<endl;
				occupy[i+1][j]=0;
	    	}
			else if (j>0 && occupy[i][j-1]==0 && board[i][j-1]==word[start]) // top
			{
				occupy[i][j-1]=1;
				flag = search(board,occupy,word,start+1,i,j-1);
				cout<<"return flag "<<flag<<endl;
				occupy[i][j-1]=0;
			}			
			else if (j<n-1 && occupy[i][j+1]==0 && board[i][j+1]==word[start])
			{
				occupy[i][j+1]=1;
				flag = search(board,occupy,word,start+1,i,j+1);
				cout<<"return flag "<<flag<<endl;
				occupy[i][j+1]=0;
			}
			if (flag) return true;
			else return false;
		}
		
			
	}
    bool exist(vector<vector<char> >& board, string word) {
		int length = word.size();   // length of the word 
		int m = board.size();    // number of rows
		int n = board[0].size();   // number of columns
		int i,j;
		vector<vector<bool> > occupy(m,vector<bool> (m,0));
		
		bool flag = false;
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				if (word[0]==board[i][j])
				{
						occupy[i][j]=1;
						flag = search(board,occupy,word,1,i,j);
						occupy[i][j]=0;
						if (flag) return true;
						
				}
			}
		}
        return false;
    }
};


int main(void)
{
	char board_char[3][4]={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string board_string[]=
	{"vpyiswkmdrpuetjwroerzxnchenphfqexpmpnxdsqvmuqxqhnwbouoqdsfsbnlgkcubpthjjcvdsuwchsdvorou",
	 "lvoniztubpwsjdbshyybuwdbqgzfzpblkpyvptpsilnrqqmxpkbjgenwlodkfexpuvmlqcdbpssgjefaqglylyv",
	 "yoakthildfxowztxpmrxxyexoninajkyxmittsewybmudgtuumtrkxobkyqkhckhovakneglhvhmbcgxpzqbzee",
	 "leuymyitndvxtbfgkcoxdsdcjfslgyprdmprkamzfhyykgfuivropxqzelmkjddorvhcvtdaccbmiihsfaguxzv",
	 "dmhnvntmeotgjpkltomgywpsbrzyratumdijqbxurrdaipnbdajdyavaswyjwtdkwnumqrjhkmhubxwgxfjxgex",
	 "adxjztokpcgeszpakbjecgcifktfszescebexpootwuovjqhkbookqyparwsrbmvfpzchpqalnojweqhggvqxwh",
	 "zneughgemwdqdtifgvupsaibioyanuinkojqxpujnabsvjybhutzwbafraffvpuffdxcuunkuoepaeshylgvoic",
	 "ikjpfzjmeokjkewwanbrnfluexcbnmfxwomenxqunadygbuioxzddlxjkbmzprxoflsvlirylwyrxvaosbrvmrg",
	 "yusykjxyriqotafulbsfanhogiidvzkttctfoqffbvvwyaqjdjqdwxuegciddsyywsekklrlhmkhoastljxigto",
	 "ovwraqqankezwsrkzfuiwuapgjmqshegedaevqfkclkyddieicmezpuhyixssdzwizberiovvavbdefoiuujjqq",
	 "jbncttdpbeshxcysyynzetgseamnlfexgtzzmeoqijxflvzjwmkagrsmtgzhlderxfslljbtszadwzpslbstumf",
	 "ovhxgkdajisxtbyovzobwnqqatjwovdeqkbzxebiovfjzgzufnvdcnuehfcvagbtseurkvcyqhjrpimvxjabxuf",
	 "gzkdcqexkiresogsgndydlmakvcluzscacfeulbhvulpirhrgmrlzdnjaqwxppzrtfwqsxxouidebnvhzmvzrik",
	 "sahrryqjrxfhqeggyqjdryabynwzggjahsraqijkhotxvadtqpyinzlnmhmupyvyqozhyirgzmfumjpdaonnnab",
	 "bjpvynsxejwnhggnfstbferkefztuzuvimsizlffudsdkytrtotysmkytlrnmoiwaaebnmhjrznbagvtuqtocfo",
	 "vqhkcxsaxuebksitkjinjqiemyxcacqxuyhyvbyvwfwixgdhpmvbedfrefvehmeemlcjpbgngevfkyncmidrnkk",
	 "rpfyztcdhpfteizrqgowsnjubtzsimeabmaafcdptliyvhrmpgkivvewoerwqxytjyurczgwmowkxpynvivsdzr",
	 "tfirxhsrrqnkvoqrdgpndelscvpwyrntwxkwfepyveisualxgamjgxeisthskunjsyhzcwzzchrwhcupegalgev",
	 "aycvkzittiasnytoaagxjktyrbyehfzkfefpdplwylqlmjzmlhlwuewngwrpbszgygybwjzwwrjickxpuilonhd",
	 "veukfomonumqqvqorjxcmizbchpswwxrctekhqyukmndjdrcorecbdgflvzjtwbwpfgyxgvhsimdlefbxkeankf",
	 "ahekacnwtserpmmyeuljhrpjozpoobvribdidqhyknpbaczgymqidfrtgijujgnrhqbmiikswcvwgxcejsmpzfk",
	 "fnwawcnpkgryobjjxnevtbaxnumeurozhkbfnrvzxoxnpiwpvdmogmothaxdtoccyginxfmwvmlkwibunoktcyp",
	 "jaomwcrydziqwpfukrfxppyjcouyruncxbrveithhezftebgxgdnwdwassylnlnmpehvocexgdecifihmlukqtk",
	 "iljtawjmnnvicymbgsgiclsjxfejwzugkfandjbryxbcxoedgkoixgtxmzgkycqljsypdbgcyhevxkbfwppuxjr",
	 "lizvhcoungscktimussrrduxbjmvjxougospsglfmdkwyukumdmeigdjsrhbpxxxnpofvznkexgctrzgwnmgtrr",
	 "niyqxyqulfktdjinnhvsaorgkeuqzlipwiftgxqudanimvxzcsrchilrohkovudrekmniehnhuvtpsstkmvtwin",
	 "lqxbnteezqsmyxvlepixgcrbndzichvpzuqmnwspmlbnixymojlxlcyyixjkhebgzrtopldbyhoggpsuyftjisk",
	 "srtcyzffywannnsomzfshwnewsxfcpruhmyfmdmkbmzoasfotmgbivfeqelsudndrnkdrzqulpjnjqdfcmimhpq",
	 "xtdspihuaufdngvitltjwjmdlylxicpfwszlbggddniqveaortxpcktpigmsjbafwzsziaelpmdkqezjzwzciur",
	 "tagljjlqhllgtlkgdzjnrpmbplattwmmwsaielalylurzgzcflpxaeyrpakkwzzutzcxmdjlqfepletrpjorpoj",
	 "govqmurgoslnfqyqgduyparipcwhrkszansokjuyefnjxmberxegyxopamytyqtaeloqwjqaqdlopouhmapmxgd",
	 "zucttuotybkozteclknbbevkqvaevijuclnvidrggbxgwdijpxlrbibtedzbljvowlleoenvfmddrlnhiyykgzf",
	 "mffnqojgkwspkyeheqkjhvwogwosfqxrvchnqsudoouamyisquczqaoyxescupvpucfmwzpmnlnbjxubrybjyrh",
	 "vvzzsrvhlzoxynpkcaxemwanoaoxyfhwdixvzsekutksgzelzerlarzorpmrxvpadnxdhbpduzxdycoagflgymv",
	 "rcjkzgabjpyoyzecwfzbebpejwrqwenniyzhebknqicrjitfnugtyxzhvrzrxmgfmioqjygagktpsoxfifzifys",
	 "arruogctukhlwhtyndrfvfeapjbyocsrtlnkrrfmcpzywswmvprsuxsjgwjxabqtndfguluyavyynwkkldchaxt",
	 "jvcgvgyqvdwbzjyajtyjjxuvkxasyxnhupppxpfssdwrmurxpshyrbwbawvavijpaygxpnshrobfiudxomyhnul",
	 "pqgqlrzctaispvkzmycsgyxgpjewyahnqoddhdfafnsukdvzdxrkyqsnzwjzwrmohstqxaqcnkwzpuytrrfphxc",
	 "ivohtfwjoocelcwnrglqyfrtziyosxtcujknogweuaiheeuvmfnklgfkpfajcvlygxludjyzligpmcmziclvith",
	 "zyjidfwbltpizyiymrhdfjqgtuuocnvelfoomkszghhfhsftlmxsypzrjtgngdrtkgiwsawyjffqzlkkzjdzaer",
	 "jzzwfcqynyilqkhrtpykojwblhgkhkdsjcqqhgqwebhxnrqhiotwarznafzhrdbchruoynmeowdbptkxkdvkwvz",
	 "wcydubgyjytzwgocwkgzzzkylntxmqwitvopyuphsijqqxtohboicygonblzuiipfyedsvlngwdwtynczbkczsq",
	 "ovdopnygswmwqijdofhmahzchcoldgbsdgivuibmeoiwytamajaaqaczeqkiynacukzosacyqnuogwchhdhadmz",
	 "hcmrdzrfvdelvgotxdqnjmqsutcuyovhshzvjscewiqtrgnqjfdurvpnorjohhwbovzzpbelmwfdeutnzyjsuyi",
	 "irtzyavcrsbqhewvqscvwyolznvthvbrnxqnxnpofshpzdmpyqlwobinqfizcmtpjjfgzuxepgvojjfjzsgpuqe",
	 "mxnmzzfpiquqpqpwhvtxhddscvysrqwenlspkxgupalfsadcywzfzcxeayyrowxeiptuozpebalvcoxakzhmdhs",
	 "dfqxvmwbwowrcxgiyitwkhvnuuugabydiqcgezhdngurdcackvawfvjzsghshhxszaydbhgqnchrejvqfvpksal",
	 "kgueobciaegffpmvdqewxorpvoehifsvlmzbpdjrhrwohkjmbqiyebpbpuizbcuoqusfxbyhvuvehhqkxakdbze",
	 "stmrwomleidlhgjodfmhotxysxivaizsdnmcdypjisupafggmsnbnnbfmmanubhzotdttscbmwrpdxvprisexwj",
	 "kilzeoideejxxbzboxudatyrkimqgizsqmtuabxefgdfkcgyzcdbvdshnexvmynckiwmmwstevyozgoyitzfwtm",
	 "myjhmhxptfnhrjznqwlgvuxveqwkpqybqiicrftnnhugsutkshrqbolfgkrvaqysahwrosgdbbmvxfgpmzfpptx",
	 "vdqtfgrxgavapnguojgkgosyarfsgyrbbhuiomhwodydshajqgtxulxxecrkbinepknfwuemzesslsbcywbvjyu",
	 "nalzbvmimwvuuryhtczlorosrktovriitvjxqvfducxovxxobwbrppjjbexwxigrdpownvbhxavsztjarkuhadq",
	"dkpahxiydaobnjcugcpbbkmdcwxlyddcnseusovxojybvavbenehzsmdpkoppttcmxygovdchbgcddfjskqsccx"};
	
	vector<vector<char> > board;
	Solution mysolution;
	string word = "a";
	int i;
	int n = board_string[0].size();
	int m = 54;
	for (i=0;i<m;i++)
	{
		vector<char> tmp(&board_string[i][0],&board_string[i][0]+n);
		board.push_back(tmp);
	}
	cout<<board[0][0]<<endl;
	
	cout<<mysolution.exist(board,word)<<endl;	
	cout<<"lalala"<<endl;
}
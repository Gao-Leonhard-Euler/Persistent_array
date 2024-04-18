#include<vector>
#include<unordered_map>
namespace my_data_struct{
	template<class T>
	class persistent_array{
		private:
			unsigned int tot,siz,vermax;
			struct node{
				unsigned int l,r;
				union{
					T val;
					struct{
						unsigned int ls,rs;
					}s;
				}data;
				node(unsigned int L,unsigned int R,unsigned int Ls,unsigned int Rs):l(L),r(R){data.s.ls=Ls;data.s.rs=Rs;}
				node(unsigned int P,const T& V):l(P),r(P){data.val=V;}
			};
			std::vector<node> v;
			std::unordered_map<unsigned int,unsigned int> mp;
			unsigned int newTree(const T* const a,unsigned int l,unsigned int r){
				v.push_back(l==r?node(l,a[l]):node(l,r,newTree(a,l,(l+r)>>1),newTree(a,((l+r)>>1)+1,r)));
				tot++;return tot-1;
			}
			T search(unsigned int n,unsigned int p)const{
				return v[n].l==v[n].r?v[n].data.val:search(p>(v[n].l+v[n].r)>>1?v[n].data.s.rs:v[n].data.s.ls,p);
			}
			unsigned int newNode(unsigned int n,unsigned int p,const T& val){
				if(v[n].l==v[n].r){
					v.push_back(node(p,val));
					tot++;return tot-1;
				}
				else{
					v.push_back(p>(v[n].l+v[n].r)>>1?node(v[n].l,v[n].r,v[n].data.s.ls,newNode(v[n].data.s.rs,p,val)):node(v[n].l,v[n].r,newNode(v[n].data.s.ls,p,val),v[n].data.s.rs));
					tot++;return tot-1;
				}
			}
		public:
			persistent_array():tot(0),vermax(0),siz(0){}
			persistent_array(const T* const l,const T* const r){
				tot=0;
				if(l&&r&&l!=r){
					siz=r-l;mp[0]=newTree(l,0,siz-1);vermax=1;
				}
				else vermax=0;
			}
			void newarray(const T* const l,const T* const r){
				if(l&&r&&l!=r){
					tot=0;vermax=1;v.clear();mp.clear();
					siz=r-l;mp[0]=newTree(l,0,siz-1);
				}
			}
			unsigned int size()const{return siz;}
			unsigned int version_size()const{return vermax;}
			bool empty()const{return siz==0;}
			T view(unsigned int loc=0,unsigned int ver=0){
				if(loc>=siz)return T();
				return search(mp[ver<vermax?ver:0],loc);
			}
			unsigned int change(unsigned int loc,const T& val,unsigned int ver=0){
				if(empty()||ver>=vermax||loc>=siz)return 0;
				mp[vermax++]=newNode(mp[ver],loc,val);
				return vermax-1;
			}
	};
}

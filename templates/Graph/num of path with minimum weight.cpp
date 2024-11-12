 if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                route[child_v]=route[v];
                min_f[child_v]=min_f[v]+1;
                max_f[child_v]=max_f[v]+1;
                st.push({dist[child_v],child_v});
            }
            else if(dist[v]+wt==dist[child_v]){
                route[child_v]+=route[v];
                route[child_v]%=mod;
                min_f[child_v]=min(min_f[v]+1,min_f[child_v]);
                max_f[child_v]=max(max_f[v]+1,max_f[child_v]);

            }

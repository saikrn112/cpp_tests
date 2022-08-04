#include <vector>
class Solution {
private:
    int islandArea(const std::vector<std::vector<int> >& grid, 
                    std::vector<std::vector<int> >& visited,
                    int i,
                    int j)
    {
        if (visited[i][j]
           || i < 0
           || i > grid.size()
           || j < 0
           || j > grid[0].size())
        {
            return 0;
        }
        
        visited[i][j] = 1;
        if (grid[i][j])
        {
            return    islandArea(grid,visited,i+1 ,j  )
                    + islandArea(grid,visited,i-1 ,j  )
                    + islandArea(grid,visited,i   ,j+1)
                    + islandArea(grid,visited,i   ,j-1);
        }
        return 0;
    }
public:
    int maxAreaOfIsland(const std::vector<std::vector<int> >& grid) 
    {
        std::vector<std::vector<int> > visited;
        for (auto i = 0; i< grid.size(); ++i)
        {
            std::vector<int> row;
            for (auto j = 0; j<grid[0].size(); ++j)
            {
                row[j] = 0;
            }
            visited.push_back(row);
        }
        
        int maxSize = 0;
        int tmpArea = 0;
        for (auto i = 0; i<grid.size(); ++i)
        {
            for (auto j = 0; j<grid[0].size(); ++j)
            {
                // if(!visited[i][j])
                // {
                //     tmpArea = islandArea(grid,visited,i,j);
                //     if (maxSize < tmpArea)
                //     {
                //         maxSize = tmpArea;
                //     }
                //     tmpArea = 0;
                // }
            }
        }
        return maxSize;
    }
};

int main()
{
}

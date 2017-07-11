class Solution {
public:
    std::vector<std::pair<int, int> > getSkyline(std::vector<std::vector<int> > &buildings) {
        std::vector<std::pair<int, int> > skyline;
        if (buildings.empty())
            return skyline;
        std::vector<std::pair<int, int> > border;
        for (auto iter = buildings.begin(); iter != buildings.end(); ++iter) {
            border.push_back(std::make_pair((*iter)[0], (*iter)[2]));
            border.push_back(std::make_pair((*iter)[1], -(*iter)[2]));
        }
        std::sort(border.begin(), border.end());
        std::multiset<int> height;
        height.insert(0);
        int pre_height = -1, pre_border = -1;
        for (auto iter = border.begin(); iter != border.end(); ++iter) {
            iter->second > 0 ? height.insert(iter->second) : height.erase(height.find(-iter->second));
            if (pre_height != *height.rbegin())
                if (pre_border != iter->first)
                    skyline.push_back(std::make_pair(pre_border = iter->first, pre_height = *height.rbegin()));
                else
                    skyline[skyline.size() - 1].second = pre_height = *height.rbegin();
        }
        auto iter = skyline.begin();
        pre_height = iter->second;
        for (++iter; iter != skyline.end();)
            if (pre_height == iter->second)
                iter = skyline.erase(iter);
            else {
                pre_height = iter->second;
                ++iter;
            }
        return skyline;
    }
};
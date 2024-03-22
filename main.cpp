#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "algorithm"

enum Countries {
    Albania = 0,
    Andorra,
    Armenia,
    Austria,
    Azerbaijan,
    Belarus,
    Belgium,
    BosniaAndHerzegovina,
    Bulgaria,
    Croatia,
    Cyprus,
    CzechRepublic,
    Denmark,
    Estonia,
    Finland,
    France,
    Germany,
    Georgia,
    Greece,
    Hungary,
    Iceland,
    Ireland,
    Italy,
    Latvia,
    Liechtenstein,
    Lithuania,
    Luxembourg,
    Malta,
    Moldova,
    Monaco,
    Montenegro,
    Netherlands,
    Macedonia,
    Norway,
    Poland,
    Portugal,
    Romania,
    Russia,
    SanMarino,
    Serbia,
    Slovakia,
    Slovenia,
    Spain,
    Sweden,
    Switzerland,
    Turkey,
    Ukraine,
    UnitedKingdom,
    VaticanCity
};

int count_countries = 49;

std::vector<std::vector<int>> graph_by_matrix(count_countries, std::vector<int>(count_countries, INT_MAX));

void Graph_to_matrix(std::unordered_map<Countries, std::unordered_set<Countries>>& graph) {
    for (auto& [Countries, neighbors] : graph) {
        int from = static_cast<int>(Countries);
        for (auto& neighbor : neighbors) {
            int to = static_cast<int>(neighbor);
            graph_by_matrix[from][to] = 1;
        }
    }

    for (int i = 0; i < count_countries; i++) {
        graph_by_matrix[i][i] = 0;
    }
}

void Floyd_Warshall() {
    for (int k = 0; k < count_countries; k++) {
        for (int i = 0; i < count_countries; i++) {
            for (int j = 0; j < count_countries; j++) {
                if (graph_by_matrix[i][k] != INT_MAX && graph_by_matrix[k][j] != INT_MAX) {
                    graph_by_matrix[i][j] = std::min(graph_by_matrix[i][j], graph_by_matrix[i][k] + graph_by_matrix[k][j]);
                }
            }
        }
    }
}

int main() {
    std::unordered_map<Countries, std::unordered_set<Countries>> graph = {
            {Albania, {Montenegro, Greece, Serbia, Macedonia}},
            {Andorra, {France, Spain}},
            {Armenia, {Azerbaijan, Georgia, Turkey}},
            {Austria, {Germany, CzechRepublic, Slovakia, Hungary, Slovenia, Italy, Switzerland, Liechtenstein}},
            {Azerbaijan, {Russia, Georgia, Armenia, Turkey}},
            {Belarus, {Latvia, Lithuania, Poland, Russia, Ukraine}},
            {Belgium, {France, Luxembourg, Germany, Netherlands}},
            {BosniaAndHerzegovina, {Croatia, Montenegro, Serbia}},
            {Bulgaria, {Romania, Serbia, Macedonia, Greece, Turkey}},
            {Croatia, {Slovenia, Hungary, Serbia, BosniaAndHerzegovina, Montenegro}},
            {Cyprus, {}},
            {CzechRepublic, {Germany, Austria, Slovakia, Poland}},
            {Denmark, {Germany}},
            {Estonia, {Latvia, Russia}},
            {Finland, {Sweden, Russia, Norway}},
            {France, {Belgium, Luxembourg, Germany, Switzerland, Italy, Spain, Andorra, Monaco}},
            {Germany, {Denmark, Netherlands, Belgium, Luxembourg, France, Switzerland, Austria, CzechRepublic, Poland}},
            {Georgia, {Russia, Azerbaijan, Armenia, Turkey}},
            {Greece, {Albania, Macedonia, Bulgaria, Turkey}},
            {Hungary, {Slovakia, Ukraine, Romania, Serbia, Croatia, Slovenia, Austria}},
            {Iceland, {}},
            {Ireland, {UnitedKingdom}},
            {Italy, {France, Switzerland, Austria, Slovenia, SanMarino, VaticanCity}},
            {Latvia, {Estonia, Lithuania, Russia, Belarus}},
            {Liechtenstein, {Switzerland, Austria}},
            {Lithuania, {Latvia, Belarus, Poland, Russia}},
            {Luxembourg, {Belgium, Germany, France}},
            {Malta, {}},
            {Moldova, {Romania, Ukraine}},
            {Monaco, {France}},
            {Montenegro, {Croatia, BosniaAndHerzegovina, Serbia, Albania}},
            {Netherlands, {Germany, Belgium}},
            {Macedonia, {Serbia, Bulgaria, Greece, Albania}},
            {Norway, {Sweden, Finland, Russia}},
            {Poland, {Germany, CzechRepublic, Slovakia, Ukraine, Belarus, Lithuania, Russia}},
            {Portugal, {Spain}},
            {Romania, {Hungary, Serbia, Bulgaria, Moldova, Ukraine}},
            {Russia, {Azerbaijan, Norway, Finland, Estonia, Latvia, Lithuania, Poland, Belarus, Ukraine, Georgia}},
            {SanMarino, {Italy}},
            {Serbia, {Hungary, Croatia, BosniaAndHerzegovina, Montenegro, Albania, Macedonia, Romania, Bulgaria}},
            {Slovakia, {CzechRepublic, Poland, Ukraine, Hungary, Austria}},
            {Slovenia, {Austria, Italy, Hungary, Croatia}},
            {Spain, {Portugal, France, Andorra}},
            {Sweden, {Norway, Finland}},
            {Switzerland, {Germany, France, Italy, Austria, Liechtenstein}},
            {Turkey, {Greece, Bulgaria, Georgia, Armenia, Azerbaijan}},
            {Ukraine, {Poland, Slovakia, Hungary, Romania, Moldova, Belarus, Russia}},
            {UnitedKingdom, {Ireland}},
            {VaticanCity, {Italy}}
    };

    Graph_to_matrix(graph);
    Floyd_Warshall();

    for (int i = 0; i < count_countries; i++) {
        std::cout << Countries(i) + 1 << "    ";
        for (int j = 0; j < count_countries; j++) {
            if (graph_by_matrix[i][j] == INT_MAX) {
                std::cout << "- ";
            } else {
                std::cout << graph_by_matrix[i][j] << " ";
            }
        }
        std::cout << '\n';
    }

    return 0;
}

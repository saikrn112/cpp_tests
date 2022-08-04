#include <iostream>
#include <string>
#include <regex>

std::pair<std::string,std::string> retPair()
{
	return {"OT","GEH1"};
}
 
int main()
{
    std::string lines[] = {"Roses are #ff0000",
                           "violets are #0000ff",
                           "all of my base are belong to you"};
 
    std::regex color_regex("#([a-f0-9]{2})"
                            "([a-f0-9]{2})"
                            "([a-f0-9]{2})");
 
    // simple match
    for (const auto &line : lines) {
        std::cout << line << ": " << std::boolalpha
                  << std::regex_search(line, color_regex) << '\n';
    }   
    std::cout << '\n';
 
    // show contents of marked subexpressions within each match
    std::smatch color_match;
    for (const auto& line : lines) {
        if(std::regex_search(line, color_match, color_regex)) {
            std::cout << "matches for '" << line << "'\n";
            std::cout << "Prefix: '" << color_match.prefix() << "'\n";
            for (size_t i = 0; i < color_match.size(); ++i) 
                std::cout << i << ": " << color_match[i] << '\n';
            std::cout << "Suffix: '" << color_match.suffix() << "\'\n\n";
        }
    }
 
    // repeated search (see also std::regex_iterator)
    std::string log(R"(
        Speed:	366
        Mass:	35
        Speed:	378
        Mass:	32
        Speed:	400
	Mass:	30)");
    std::regex r(R"(Speed:\t\d*)");
    std::smatch sm;
    while(regex_search(log, sm, r))
    {
        std::cout << sm.str() << '\n';
        log = sm.suffix();
    }
 
	std::string symbol = "GEH1-GEJ1";
	std::regex sym_regex("([A-Z]+)([A-Z][0-9])-(\\1)([A-Z][0-9])");
	std::cout << symbol << ":" << std::regex_search(symbol,sym_regex)<< std::endl;
	std::smatch matches;
	if (std::regex_search(symbol,matches,sym_regex))
	{
		std::cout << "matches for '" << symbol << "'\n";
		std::cout << "Prefix: '" << matches.prefix() << "'\n";
		for (size_t i = 0; i< matches.size(); ++i)
		{
			std::cout << i << ": " << matches[i] << "\n";
		}
		std::cout << "Suffix: " << matches.suffix() << "\n";
	 
	}

	std::string outrightSymbol = "GEH1";
	std::regex out_sym_regex("([A-Z]+)([A-Z][0-9])");
	std::cout << outrightSymbol << ":" << std::regex_search(outrightSymbol,out_sym_regex)<< std::endl;
	std::smatch out_matches;
	if (std::regex_search(outrightSymbol,out_matches,out_sym_regex))
	{
		std::cout << "matches for '" << outrightSymbol << "'\n";
		std::cout << "Prefix: '" << out_matches.prefix() << "'\n";
		for (size_t i = 0; i< out_matches.size(); ++i)
		{
			std::cout << i << ": " << out_matches[i] << "\n";
		}
		std::cout << "Suffix: " << matches.suffix() << "\n";
	 
	}

	std::string type,inst;
	std::tie(type,inst) = retPair();
	std::cout << type << " : " << inst << std::endl;
}


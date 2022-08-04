#include <benchmark/benchmark.h>
#include <vector>
#include <string>
#include <sstream>
#include "Nullable.h"
#include <optional>

//static void bench_push_back(benchmark::State& state)
//{
//    while (state.KeepRunning())
//    {
//        std::vector<int> v;
//        v.push_back(12);
//    }
//}
//BENCHMARK(bench_push_back);

Nullable<std::string> getNullableString(bool isTrue)
{
    if (isTrue)
    {
        std::stringstream ss;
        ss << " isTrue:1b,fa;d;fakjd;flkajd;flkja;lkdnmcvl;askdjfioahdkjnvkajhgoaheurtyaotjsdl;fknasd;lkfhjas;dhgas;ldnvsadhgal;dihgjalsd;nfalsdkghaod;gn;alsdkghadlghasdgnklal'sdknmfalkgjasldkgnasdnguaytojthtlaksndioweht8923;4ljasl;dnfkas;jdgbask;jdnkajsghau3ho2nlenvaksjdhgao;glaksdnfksadhjg;alsdnglsadkhgioeh2o;ij3o9u;laskndf,nals;kdjnfla;ndl;jkdfja;dkfjdi;fja;fjdf;klasdjfa;lkdjfladifjidfe;akdjf;lkjfd;ja;lje;";
        return {ss.str()};
    }
    return Nullable<std::string>();
}

static void bench_nullable_string(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        auto nullString = getNullableString(true);
        if (nullString)
        {
            auto data = *nullString;
        }
    }
}

std::optional<std::string> getOptionalString(bool isTrue)
{
    if (isTrue)
    {
        std::stringstream ss;
        ss << " isTrue:1b,fa;d;fakjd;flkajd;flkja;lkdnmcvl;askdjfioahdkjnvkajhgoaheurtyaotjsdl;fknasd;lkfhjas;dhgas;ldnvsadhgal;dihgjalsd;nfalsdkghaod;gn;alsdkghadlghasdgnklal'sdknmfalkgjasldkgnasdnguaytojthtlaksndioweht8923;4ljasl;dnfkas;jdgbask;jdnkajsghau3ho2nlenvaksjdhgao;glaksdnfksadhjg;alsdnglsadkhgioeh2o;ij3o9u;laskndf,nals;kdjnfla;ndl;jkdfja;dkfjdi;fja;fjdf;klasdjfa;lkdjfladifjidfe;akdjf;lkjfd;ja;lje;";
        return std::optional<std::string>(ss.str());
    }
    return std::optional<std::string>();
}

static void bench_optional_string(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        auto nullString = getOptionalString(true);
        if (nullString)
        {
            auto data = *nullString;
        }
    }
}
BENCHMARK(bench_nullable_string);
BENCHMARK(bench_optional_string);
BENCHMARK_MAIN();

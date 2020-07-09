#define BOOST_TEST_MODULE tests

#include <boost/test/unit_test.hpp>
#include <string>
#include <memory>
#include "observer.h"

BOOST_AUTO_TEST_SUITE(suite1)

BOOST_AUTO_TEST_CASE(case1)
{
    const int size{1};
    Subject subj(size);

    subj.AddSub(std::make_unique<FileObserver>(subj));
    subj.AddSub(std::make_unique<CoutObserver>(subj));

    BOOST_CHECK_EQUAL(subj.SizeOfSubs(), 2);
}

BOOST_AUTO_TEST_SUITE_END()
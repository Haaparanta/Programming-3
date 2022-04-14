#include <QString>
#include <QtTest>
#include "morottaja.hh"
/**
 * @brief The MorottajaTest class
 */
class MorottajaTest : public QObject
{
    Q_OBJECT

public:
    MorottajaTest();

private Q_SLOTS:
    /**
     * @brief testMorjesta tests the basic morotus
     */
    void testMorjesta();
    /**
     * @brief testPersonalizedMorjesta test the overloaded version of morjesta
     */
    void testPersonalizedMorjesta();

    /**
     * @brief testMorotusCounter a very simple test for the counter
     * The test coverage should be improved.
     */
    void testMorotusCounter();
private:
    std::string const testPerson = "Pekka";

};

MorottajaTest::MorottajaTest()
{
}

void MorottajaTest::testMorjesta()
{
    Morottaja m;
    QCOMPARE(m.morjesta(), std::string("Morjesta Manse!"));
}

void MorottajaTest::testPersonalizedMorjesta()
{
    Morottaja m;
    QCOMPARE(m.morjesta(testPerson), std::string("Morjesta, " + testPerson + "!"));

}

void MorottajaTest::testMorotusCounter()
{
    Morottaja m;
    QCOMPARE(m.montakoMorotettu(), 0u);
    m.morjesta(testPerson);
    QCOMPARE(m.montakoMorotettu(), 1u);
    m.morjesta(testPerson);
    QCOMPARE(m.montakoMorotettu(), 2u);
}



QTEST_APPLESS_MAIN(MorottajaTest)

#include "morottajatest.moc"

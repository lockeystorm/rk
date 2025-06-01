#include <gtest/gtest.h>
#include "../source/maptile.h"
#include "../source/maptileproxy.h"
#include "../source/map.h"

class MapTileTest : public ::testing::Test {
protected:

    std::stringstream ss;
    std::streambuf* old_buf;
    
    void SetUp() override {
        old_buf = std::cout.rdbuf();
        std::cout.rdbuf(ss.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(old_buf);
    }
};

TEST_F(MapTileTest, InitializationAndDrawWorksCorrectly) {
    MapTile tile(0, 0, 12.3, 45.6);
    
    // проверяем, что при создании tile загрузился resource
    EXPECT_NE(ss.str().find("* Load Resource. (Heavy Work) *"), std::string::npos); 

    EXPECT_DOUBLE_EQ(tile.CenterX(), 0);
    EXPECT_DOUBLE_EQ(tile.CenterY(), 0);
    EXPECT_DOUBLE_EQ(tile.Width(), 12.3);
    EXPECT_DOUBLE_EQ(tile.Height(), 45.6);

    // проверяем, что при вызове draw произошла отрисовка
    ss.str(""); // очищаем буфер
    tile.Draw();
    EXPECT_NE(ss.str().find("* Draw MapTile from resouce. *"), std::string::npos); 
}

class MapTileProxyTest : public ::testing::Test {
protected:

    std::stringstream ss;
    std::streambuf* old_buf;
    
    void SetUp() override {
        old_buf = std::cout.rdbuf();
        std::cout.rdbuf(ss.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(old_buf);
    }    
};

TEST_F(MapTileProxyTest, InitializationWorksCorrectly) {
    MapTileProxy proxytile(0, 0, 10.0, 20.0);
    
    // проверяем, что при создании proxytile не было вывода от Resource
    EXPECT_TRUE(ss.str().empty()); 
    
    // проверяем, что при вызове draw создался объект(загрузился resource) и произошла отрисовка
    proxytile.Draw();
    EXPECT_NE(ss.str().find("Load Resource"), std::string::npos); 
    EXPECT_NE(ss.str().find("Draw MapTile"), std::string::npos);
    
    EXPECT_DOUBLE_EQ(proxytile.CenterX(), 0);
    EXPECT_DOUBLE_EQ(proxytile.CenterY(), 0);
    EXPECT_DOUBLE_EQ(proxytile.Width(), 10.0);
    EXPECT_DOUBLE_EQ(proxytile.Height(), 20.0);
}

TEST_F(MapTileProxyTest, SecondDrawDoesntCreateNewObject){
    MapTileProxy proxytile(0, 0, 10.0, 20.0);
    
    // проверяем, что второй вызов draw не создает новый объект, т.е. не происходит 2 загрузка resource
    proxytile.Draw();
    ss.str("");
    proxytile.Draw();
    EXPECT_NE(ss.str().find("Draw MapTile"), std::string::npos);
    EXPECT_EQ(ss.str().find("Load Resource"), std::string::npos);
}

class MapTest : public ::testing::Test {
protected:

    std::stringstream ss;
    std::streambuf* old_buf;
    
    void SetUp() override {
        old_buf = std::cout.rdbuf();
        std::cout.rdbuf(ss.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(old_buf);
    }

};

TEST_F(MapTest, PrintWorksCorrectly) {
    Map map(0, 0, 60, 90, 2, 2);
    
    // проверяем, что при draw=false не создаются maptile
    map.Print(false);
    EXPECT_EQ(ss.str().find("Load Resource"), std::string::npos);
    ss.str("");
    
    // проверяем, что при draw=true создаются все maptile
    map.Print(true);
    size_t count = 0;
    size_t pos = 0;
    std::string s = "* Load Resource. (Heavy Work) *";
    while ((pos = ss.str().find(s, pos)) != std::string::npos) {
        ++count;
        pos += s.length();
    }
    EXPECT_EQ(count, 4);
    ss.str("");
    
    // проверяем, что при втором print с draw=true не создаются новые maptile
    map.Print(true);
    EXPECT_NE(ss.str().find("Draw MapTile"), std::string::npos);
    EXPECT_EQ(ss.str().find("Load Resource"), std::string::npos);
}

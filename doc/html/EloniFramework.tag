<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>ConfigurationManager.h</name>
    <path>/home/ymejan/Development/EloniFramework/inc/</path>
    <filename>ConfigurationManager_8h</filename>
    <class kind="class">ConfigurationManager</class>
  </compound>
  <compound kind="file">
    <name>DatabaseManager.h</name>
    <path>/home/ymejan/Development/EloniFramework/inc/</path>
    <filename>DatabaseManager_8h</filename>
    <class kind="class">DatabaseManager</class>
  </compound>
  <compound kind="file">
    <name>SecurityManager.h</name>
    <path>/home/ymejan/Development/EloniFramework/inc/</path>
    <filename>SecurityManager_8h</filename>
    <class kind="class">SecurityManager</class>
  </compound>
  <compound kind="file">
    <name>ShellManager.h</name>
    <path>/home/ymejan/Development/EloniFramework/inc/</path>
    <filename>ShellManager_8h</filename>
    <class kind="class">ShellManager</class>
  </compound>
  <compound kind="class">
    <name>ConfigurationManager</name>
    <filename>classConfigurationManager.html</filename>
    <member kind="function">
      <type>std::string</type>
      <name>getConfig</name>
      <anchorfile>classConfigurationManager.html</anchorfile>
      <anchor>ad3e85ee715420c432cd7545c6aaf8314</anchor>
      <arglist>(std::string var)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setConfig</name>
      <anchorfile>classConfigurationManager.html</anchorfile>
      <anchor>ad027e09a69a516f2ad020c9cbdf49f2f</anchor>
      <arglist>(std::string var, std::string val)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DatabaseManager</name>
    <filename>classDatabaseManager.html</filename>
    <member kind="function">
      <type>int</type>
      <name>Open</name>
      <anchorfile>classDatabaseManager.html</anchorfile>
      <anchor>a37b1f9148ca1b698c73a98bece97cd35</anchor>
      <arglist>(std::string filename)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Close</name>
      <anchorfile>classDatabaseManager.html</anchorfile>
      <anchor>a5232ac6d9271e2b3984042c306157bdb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::map&lt; std::string, std::string &gt; &gt;</type>
      <name>Query</name>
      <anchorfile>classDatabaseManager.html</anchorfile>
      <anchor>adefb1bdb51d7b23d4b3a446a3f22ea26</anchor>
      <arglist>(std::string, std::string=&quot;elonisas.db&quot;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>EloniFramework</name>
    <filename>classEloniFramework.html</filename>
    <member kind="function" static="yes">
      <type>static DatabaseManager *</type>
      <name>Database</name>
      <anchorfile>classEloniFramework.html</anchorfile>
      <anchor>a803da824e33d75564d5a7ca77e66b0e4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ConfigurationManager *</type>
      <name>Configuration</name>
      <anchorfile>classEloniFramework.html</anchorfile>
      <anchor>a3ef2e10a4eae52e233931cff12aadb48</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static SecurityManager *</type>
      <name>Security</name>
      <anchorfile>classEloniFramework.html</anchorfile>
      <anchor>a417d0368e8e814f717a2b210496f7db2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ShellManager *</type>
      <name>Shell</name>
      <anchorfile>classEloniFramework.html</anchorfile>
      <anchor>ac0bcb257424435f01d2da61a816db01a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>Path</name>
      <anchorfile>classEloniFramework.html</anchorfile>
      <anchor>a97ba3c1e7eed84a52a572794c6f78eab</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SecurityManager</name>
    <filename>classSecurityManager.html</filename>
    <member kind="function">
      <type>std::string</type>
      <name>Encrypt</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>acc4ef8e7685038735e83e73556a5f510</anchor>
      <arglist>(std::string str)</arglist>
    </member>
    <member kind="function">
      <type>std::map&lt; std::string, int &gt;</type>
      <name>getRoles</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>afe3d50265be58ec179058feadd9902a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasRole</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>a2950edc6463999ceca399d47023adddc</anchor>
      <arglist>(std::string username, std::string role)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addRole</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>a9ebf385f13f1893bb36647605677043d</anchor>
      <arglist>(std::string username, std::string role)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeRole</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>a2d5b4923acbe73b0d21c5179deb7f17d</anchor>
      <arglist>(std::string username, std::string role)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addUser</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>ac9dc2c5a7667b95d9850ff22fc897213</anchor>
      <arglist>(std::string username, std::string password)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setUser</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>ad616d32abdd366d50dfd01091d6a1f0c</anchor>
      <arglist>(std::string username, std::string var, std::string val)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteUser</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>a61db3bbbb21105c441d2a7bc75fb41bd</anchor>
      <arglist>(std::string username)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isUser</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>abda859f83e39977a46ce993970a35f92</anchor>
      <arglist>(std::string username)</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::string &gt;</type>
      <name>getUsers</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>a05f3c7fc498871277a00dffa092614c1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Authenticate</name>
      <anchorfile>classSecurityManager.html</anchorfile>
      <anchor>ace68188567f645c18097b8791db64b41</anchor>
      <arglist>(std::string username, std::string password)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ShellManager</name>
    <filename>classShellManager.html</filename>
    <member kind="function">
      <type></type>
      <name>ShellManager</name>
      <anchorfile>classShellManager.html</anchorfile>
      <anchor>a04dec3699269bb388648f6017fd9fd15</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>setUser</name>
      <anchorfile>classShellManager.html</anchorfile>
      <anchor>a9e595c79f89d7c796df213b469384e08</anchor>
      <arglist>(std::string Username)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>setUser</name>
      <anchorfile>classShellManager.html</anchorfile>
      <anchor>a0451c163858db5c51c8976d9bf7dd37d</anchor>
      <arglist>(int UserID)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>setWorkingDirectory</name>
      <anchorfile>classShellManager.html</anchorfile>
      <anchor>aeed1b234a317e951f01bdc42a2097d40</anchor>
      <arglist>(std::string dir)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>Execute</name>
      <anchorfile>classShellManager.html</anchorfile>
      <anchor>a9f40b1296bef8f0d694cafdca29e0e13</anchor>
      <arglist>(std::string cmd)</arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>inc</name>
    <path>/home/ymejan/Development/EloniFramework/inc/</path>
    <filename>dir_bfccd401955b95cf8c75461437045ac0.html</filename>
    <file>ConfigurationManager.h</file>
    <file>DatabaseManager.h</file>
    <file>EloniFrameWork.h</file>
    <file>Includes.h</file>
    <file>SecurityManager.h</file>
    <file>ShellManager.h</file>
  </compound>
  <compound kind="dir">
    <name>src</name>
    <path>/home/ymejan/Development/EloniFramework/src/</path>
    <filename>dir_68267d1309a1af8e8297ef4c3efbcdba.html</filename>
    <file>ConfigurationManager.cpp</file>
    <file>DatabaseManager.cpp</file>
    <file>EloniFrameWork.cpp</file>
    <file>SecurityManager.cpp</file>
    <file>ShellManager.cpp</file>
  </compound>
</tagfile>

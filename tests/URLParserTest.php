<?php
require_once "../parseurl.php";

class URLParserTest extends PHPUnit_Framework_TestCase
{
    /*
    * Tests Url::parse on valid url with http scheme and host
    */
    public function testparse1()
    {
        $actual = Url::parse("http://www.wetter24.de");
        $this->assertEquals('http', $actual["scheme"]);
        $this->assertEquals('www.wetter24.de', $actual["host"]);
    }

    /*
    * Tests Url::parse on valid url with http scheme and host
    */
    public function testparse2()
    {
        $actual = Url::parse("http://some.thing");
        $this->assertEquals('http', $actual["scheme"]);
        $this->assertEquals('some.thing', $actual["host"]);
    }

    /*
    * Tests Url::parse on valid url with ftp scheme and host
    */
    public function testparse3()
    {
        $actual = Url::parse("ftp://a.large.site");
        $this->assertEquals('ftp', $actual["scheme"]);
        $this->assertEquals('a.large.site', $actual["host"]);
    }

    /*
    * Tests Url::parse on valid url with http scheme, host and path
    */
    public function testparse4()
    {
        $actual = Url::parse("http://a.site.with/a-path");
        $this->assertEquals('http', $actual["scheme"]);
        $this->assertEquals('a.site.with', $actual["host"]);
        $this->assertEquals('/a-path', $actual["path"]);
    }

    /*
    * Tests Url::parse on empty value
    */
    public function testparseemptyvalue()
    {
        $actual = Url::parse("");
        $this->assertEquals(false, $actual);
    }

    /*
   * Tests Url::parse on  url with protocol
   */
    public function testparseincompleteurl()
    {
        $actual = Url::parse("blabla");
        $this->assertEquals("blabla", $actual["path"]);
    }

    /*
   * Tests Url::parse on spaces in url
   */
    public function testparsespacesl()
    {
        $actual = Url::parse("http://a.site.with/a-path   ");
        $this->assertEquals('http', $actual["scheme"]);
        $this->assertEquals('a.site.with', $actual["host"]);
        $this->assertEquals('/a-path   ', $actual["path"]);
    }



}
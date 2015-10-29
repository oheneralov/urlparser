<?php


class Url {
	/*
	 *  Parse a URL and return its components (scheme, host, port, path etc.)
	 * if url is incorrect then it will try to parse it anyway
	 * This class doesn't work with relative URLs.
	 */
	public static function parse($url){
		$result = parse_url($url);
		if(!$url){
			return false;
		}
		if (!is_array($result)){
			return false;
		}
		return $result;
	}

}

$result = "";
if (isset($_GET["url"])){
	$urltoparse = $_GET["url"];
	//check if it is a valid url
	$result = Url::parse($urltoparse);

}
print_r($result);



?>
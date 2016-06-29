<?php
// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
class dbConnect{
	
	private $host = "localhost";
	private $user = "root";
	private $password = "root";
	private $db = "StockForecasting";

	public function getHost(){
		return $this->host;
	}
	public function getUser(){
		return $this->user;
	}
	public function getPassword(){
		return $this->password;
	}
	public function getDB(){
		return $this->db;
	}
}

?>
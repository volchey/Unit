<?php

class Color
{
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	public static $verbose = False;
	private $unpack;
	private $new;

	public static function doc() {
		return (readfile('Color.doc.txt'));
	}

	public function __construct(array $kwargs)
	{
		if (array_key_exists('rgb', $kwargs))
		{
			$this->unpack = (unpack('C*', pack('L', $kwargs['rgb'])));
			$this->red = $this->unpack[3];
			$this->green = $this->unpack[2];
			$this->blue = $this->unpack[1];
		}
		else
		{
			if (array_key_exists('red', $kwargs))
				$this->red = $kwargs['red'];
			if (array_key_exists('green', $kwargs))
				$this->green = $kwargs['green'];
			if (array_key_exists('blue', $kwargs))
				$this->blue = $kwargs['blue'];
		}
		if (self::$verbose == True)
			printf("Color( red: %3d, green %3d, blue %3d ) constructed.\n", $this->red, $this->green, $this->blue);
		return ;
	}

	public function add($color) {
		return (new Color( array('red' => $color->red + $this->red, 'green' => $color->green + $this->green,
			'blue' => $color->blue + $this->blue)));
	}

	public function sub($color) {
		return (new Color( array('red' => $this->red - $color->red, 'green' => $this->green - $color->green,
			'blue' => $this->blue - $color->blue)));
	}
	
	public function mult($color) {
		return (new Color( array('red' => $this->red * $color->red, 'green' => $this->green * $color->green,
			'blue' => $this->blue * $color->blue)));
	}
	
	public function __destruct()
	{
		if (self::$verbose == True)
			printf("Color( red: %3d, green %3d, blue %3d ) destructed.\n", $this->red, $this->green, $this->blue);
		return ;
	}

	public function __toString() {
		return (sprintf("Color( red: %3d, green %3d, blue %3d )", $this->red, $this->green, $this->blue));
	}
}

?>
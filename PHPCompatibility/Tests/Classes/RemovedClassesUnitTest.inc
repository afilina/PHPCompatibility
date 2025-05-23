<?php

/*
 * These should not be flagged.
 */
$okay = new StdClass();
$okay = new \myNamespace\SWFAction();
$okay = \myNamespace\SWFAction::static_method();
$okay = SomeNamespace\SWFAction::static_method();

$snon = new class extends \My\SWFFill {};
new class extends My\SWFFont {};

class MyClass {
    function SWFSoundTypeHint( myNameSpace\SWFSound $a ) {}
    function SWFSpriteTypeHint( \some\other\SWFSprite $a ) {}
}

try {
} catch (\My\Except\DOMException $e) { // TODO
}

function NsSWFMovieReturnTypeHint( $a ) : \SomeNamespace\SWFMovie {}
function NsNullSWFMovieReturnTypeHint( $a ) : ?SomeNamespace\SWFMovie {}
function NoSWFMovieReturnTypeHint( $a ) : \SomeNamespace\SWFMovie\RealClass {}

/*
 * 1. Verify instantiation without parameters is being flagged.
 * 2. + 3. Verify that instantion with spacing/comments between elements is being flagged.
 * 4. Verify that instation with global namespace indicator is being flagged.
 */
$test = new SWFAction;
$test = new SWFAction ();
$test = new /*comment*/ SWFAction();
$test = new \SWFAction();

class MySWFBitmap extends SWFBitmap {}
echo SWFButton::$property;
echo SWFDisplayItem::method_call();
echo SWFFill::CLASS_CONSTANT;
$anon = new class extends \SWFFont {};

class TypeHints {
    function SWFFontCharTypeHint(SWFFontChar $param) {}
    function SWFGradientTypeHint($a, SWFGradient $b) {}
    function SWFMorphTypeHint(\SWFMorph $param) {}
    function SWFMovieTypeHint( ?SWFMovie $param) {}
    function SWFPrebuiltClipTypeHint(?\SWFPrebuiltClip $param) {}
    function SWFShapeDefault($param = SWFShape::CLASS_CONSTANT) {}
    function SWFSoundDefault($param = \SWFSound::CLASS_CONSTANT) {}
    function SWFSoundInstanceReturnType($param): ?SWFSoundInstance {}
    function SWFSpriteReturnType($param): \SWFSprite {}
}

echo \SWFText::$property;
echo \SWFTextField::method_call();
echo \SWFVideoStream::CLASS_CONSTANT;

$closure = function() : HW_API {};
$closure = function() : \HW_API_Object {};
$closure = function() : ?\HW_API_Attribute {};
$closure = function() : ?HW_API_Error {};
$obj = new HW_API_Content;
echo HW_API_Reason::$property;

$anon = new class extends SQLiteDatabase {};
echo SQLiteResult::numFields();
function SqlLiteTypeHint(SQLiteUnbuffered $param) {}
try {} catch (SQLiteException $e) {}

function XmlRpcServerTypeHint(XmlRpcServer $server) {}
function XmlRpcServerTypeHint(
    $server
): XmlRpcServer {}

// Test support for PHP 7.4 property types.
public SWFButton $var; // Ignore, not a property, parse error.

$anon = class() {
    public SQLiteDatabase $property;
};

// Test support for PHP 7.4 arrow functions.
$fn = fn(SWFDisplayItem $param) => $param;
$fn = fn($param): SWFTextField => $param;

// Test support for PHP 8.0 union types.
class UnionTypes {
    public NotATarget|AlsoNotATarget $okay;

    public HW_API_Content|HW_API_Reason $property;
    public function paramType(SWFFill|SWFFont $param) {}
    public function returnType($param) : SQLiteResult|SQLiteUnbuffered {}
}

// Test support for PHP 8.1 intersection types.
class IntersectionTypes {
    public function paramType(NotATarget&AlsoNotATarget $okay) {}

    public SWFMorph&SWFMovie $property;
    public function paramType(SWFSprite&\SWFText $param) {}
    public function returnType($param) : HW_API_Object&HW_API_Attribute {}
}

function CheckAllTypeParts(
    NotATarget|SWFButton $a
) : NotATarget|SQLiteException {}

// Test support for PHP 8.2 DNF types.
class DNFTypes {
    public function paramTypeA(NotATarget&AlsoNotATarget $okay) {}

    public int|(SWFMorph&SWFMovie) $property;
    public function paramTypeB((SWFSprite&\SWFText)|false $param) {}
    public function returnType($param) : SomethingElse|(HW_API_Object&HW_API_Attribute) {}
}

function mailMe(): IMAP\Connection {}

$oci8 = new OCICollection();
$closure = function(OCILob $lob) {};

function my_pspell(
    PSpell\Config $config,
    PSpell\Dictionary $dictionary,
) {}

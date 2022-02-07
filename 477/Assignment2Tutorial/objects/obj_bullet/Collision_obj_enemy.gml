// remove 1 hp on bullet collison with enemy and delete that bullet
with (other)
{
	hp = hp -1;
}
instance_destroy();
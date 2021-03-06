<?php

include_once ("class.ticket_base.inc");

class ticket_transfer extends ticket_base
{

	function ticket_transfer()
	{
		parent::ticket_base("ticket_transfer", NF_NO_ADD|NF_SPECIFIC_5|NF_NO_EXTENDED_SEARCH);

		$this->add(new atkAttribute("id", AF_AUTOKEY|AF_HIDE, array(255,10,10)));

		$this->add(new atkManyToOneRelation("type_id", "tickets.ticket_types", AF_READONLY|AF_OBLIGATORY|AF_SEARCHABLE));

		$this->add(new atkManyToOneRelation("status_id", "tickets.ticket_status", AF_OBLIGATORY));

		$this->add(new atkDateAttribute("date_created", AF_OBLIGATORY|AF_DATE_EDIT_NO_DAY|AF_DATE_NO_CALENDAR));

		$this->add(new atkAttribute("ticket_number", AF_LARGE|AF_SEARCHABLE|AF_READONLY|AF_UNIQUE));

		$this->add(new atkAttribute("external_number", AF_SEARCHABLE));
		$this->getAttribute("external_number")->setLabel(atktext('place_of_transfer'));
		$this->getAttribute("external_number")->setAttribSize(array(255,15,15));

		$this->setOrder("date_created DESC");
		$this->setTable("tickets");

		$this->addFilter($this->getUserTablePrefix()."tickets.type_id = 1007 OR ".$this->getUserTablePrefix()."tickets.type_id = 1008");

	}

	/*
	 * custom display, replace external_number ID with name
	 */
	function external_number_display(&$record)
	{
		if ($record['external_number'])
		{
			$location_to = $this->getLocationData($record['external_number']);
			$record['external_number'] = $location_to['name'];
		}

		return $this->m_attribList["external_number"]->display($record);
	}

}

?>

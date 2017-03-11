<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE stylesheet SYSTEM "wwnz_entities.dtd">
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:variable name="message">mailto:safety@[].org.nz[rivers]?subject=Report for NZRCA Accident/Incident Database&amp;body=Please correct the email address above by moving 'rivers' to the gap and removing [] characters.%0A
Check http://rivers.org.nz/article/about-accident-incident-database#Definitions for the data to include in your report.%0A
Please note the NZRCA policy for the Accident/Incident database at http://rivers.org.nz/article/about-accident-incident-database#Policy%0A
%0A
Date and Time:%0A
Type:%0A
Type Modifier:%0A
Victims:%0A (Names are used for cross-referencing with other sources, but not published directly in the database.) Please supply name, age, sex and nationality.%0A
Location:%0A
Location description:%0A
Class:%0A
Flow:%0A
Boat Type:%0A
Boat description:%0A
Trip Type:%0A
Summary:%0A
Discussion:%0A
Documents:%0A
Reporter:%0A
</xsl:variable>

<xsl:template match="@*|node()">
   <xsl:copy>
      <xsl:apply-templates select="@*|node()"/>
   </xsl:copy>
</xsl:template>

<xsl:template name="doIncidentNav">
  <p><a href="/safety/db" title="Home page for the Accident/Incident Database">Accident/Incident Database</a> | <a href="/safety/db/list/date" title="List all Incidents by Date">List all by Date</a> | <a href="/safety/db/list/river" title="List all Incidents by River">List all by River</a> | <a href="/safety/db/statistics" title="Statistics from the database">Statistics</a> | <a href="/article/about-accident-incident-database" title="About the Accident/Incident Database">About</a> | <a href="{$message}">Report an Incident</a></p>
</xsl:template>

<!--  Global rule for formatting date and time
  dateTime parameter should be formatted to XML Schema dateTime -->
<xsl:template name="showDateAndTime">
  <xsl:param name="dateTime">0000-00-00T00:00:00.000</xsl:param>
  <xsl:param name="suppressTime"></xsl:param>
  <xsl:variable name="year"><xsl:value-of select="substring($dateTime,1,4)"/></xsl:variable>
  <xsl:variable name="month"><xsl:value-of select="substring($dateTime,6,2)"/></xsl:variable>
  <xsl:variable name="day"><xsl:value-of select="substring($dateTime,9,2)"/></xsl:variable>
  <xsl:variable name="hours"><xsl:value-of select="substring($dateTime,12,2)"/></xsl:variable>
  <xsl:variable name="minutes"><xsl:value-of select="substring($dateTime,15,2)"/></xsl:variable>
  
  <!-- remove leading zero from day if it exists -->
  <xsl:variable name="strippedDay">
    <xsl:if test="starts-with($day,'0')">
      <xsl:value-of select="substring($day,2,1)"/>
    </xsl:if>
    <xsl:if test="not(starts-with($day,'0'))">
      <xsl:value-of select="$day"/>
    </xsl:if>
  </xsl:variable>
  
  <xsl:variable name="monthName">
    <xsl:call-template name="getCurrentMonthName">
      <xsl:with-param name="index" select="$month"/>
    </xsl:call-template>
  </xsl:variable>
  
  <xsl:if test="$strippedDay !='0'"><xsl:value-of select="$strippedDay"/>&nbsp;</xsl:if><xsl:value-of select="$monthName"/>&nbsp;<xsl:value-of select="$year"/>
  <xsl:if test="string($suppressTime) != 'true'">&nbsp;<xsl:value-of select="$hours"/>:<xsl:value-of select="$minutes"/></xsl:if>
</xsl:template>

<!-- Generate the month name from month number for option boxes, date displays, etc. -->
<xsl:template name="getCurrentMonthName">
  <xsl:param name="index" />
  <xsl:choose>
    <xsl:when test="$index=1">January</xsl:when>
    <xsl:when test="$index=2">February</xsl:when>
    <xsl:when test="$index=3">March</xsl:when>
    <xsl:when test="$index=4">April</xsl:when>
    <xsl:when test="$index=5">May</xsl:when>
    <xsl:when test="$index=6">June</xsl:when>
    <xsl:when test="$index=7">July</xsl:when>
    <xsl:when test="$index=8">August</xsl:when>
    <xsl:when test="$index=9">September</xsl:when>
    <xsl:when test="$index=10">October</xsl:when>
    <xsl:when test="$index=11">November</xsl:when>
    <xsl:when test="$index=12">December</xsl:when>
  </xsl:choose>
</xsl:template>

</xsl:stylesheet>
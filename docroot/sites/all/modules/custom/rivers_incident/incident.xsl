<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE stylesheet SYSTEM "wwnz_entities.dtd">
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:import href="common.xsl"/>

<!-- id is set in incident.module -->
<xsl:variable name="pageTitleForBreadcrumb">Incident <xsl:value-of select="$id"/></xsl:variable>

<xsl:template match="/incidents">
  <xsl:call-template name="doIncidentNav"/>

  <xsl:apply-templates select="incident[@id=$id]"/>
</xsl:template>

<!-- want to set page Changed date to that of the current Incident record -->

<xsl:variable name="myChanged">
  @@@@@<xsl:value-of select="/page/content/article/incident[@id=$id]/changed"/>
</xsl:variable>


<xsl:template match="incident">
  <!-- if the Feedback form has been submitted, suppress the Incident data -->
  
  <xsl:if test="not(/page/content/form[@id='feedback']/errors)">
  <div class="incident" style="margin: 0px 0px 5px 0px;">
  <xsl:value-of select="@id"/><sup><a class="definition" title="A unique identifier for each Incident (currently based on date)" href="/article/about-accident-incident-database#Id">?</a></sup>, 
  <xsl:call-template name="showDateAndTime">
      <xsl:with-param name="dateTime"><xsl:value-of select="dateTime"/></xsl:with-param>
    </xsl:call-template><sup><a class="definition" title="Date and time of incident" href="/article/about-accident-incident-database#DateTime">?</a></sup>,
    <xsl:value-of select="type"/><sup><a class="definition" title="Type of incident. One of Fatal accident | Injury incident | Near-miss." href="/article/about-accident-incident-database#Type">?</a></sup> /
    <xsl:value-of select="typeModifier"/><sup><a class="definition" title="Type modifier. One of One of Entrapment-Tree | Entrapment-Sieve | Entrapment-Other | Swim | Shoulder dislocation." href="/article/about-accident-incident-database#TypeModifier">?</a></sup>
    <br/>
    <xsl:choose><xsl:when test="count(victim) &gt; 1">Victims</xsl:when><xsl:otherwise>Victim</xsl:otherwise></xsl:choose><sup><a class="definition" title="The person(s) at risk of harm, or who suffered harm in the incident" href="/article/about-accident-incident-database#Victim">?</a></sup>:
    <xsl:for-each select="victim">
    <!-- <strong><xsl:value-of select="victim/name"/></strong> --> <xsl:value-of select="nationality"/>, <xsl:if test="age"><xsl:value-of select="age"/>, </xsl:if><xsl:choose>
        <xsl:when test="sex = 'F'">Female</xsl:when>
        <xsl:otherwise>Male</xsl:otherwise>
      </xsl:choose>
      <xsl:if test="position() != last()">.&nbsp;</xsl:if>
    </xsl:for-each>
    <br/>
    Location<sup><a class="definition" title="Region/River[/Section][/Feature]" href="/article/about-accident-incident-database#Location">?</a></sup>: <strong><xsl:value-of select="location/region"/>/<xsl:value-of select="location/river"/><xsl:if test="location/river != location/section">/<xsl:value-of select="location/section"/></xsl:if></strong><xsl:if test="location/description">/<xsl:value-of select="location/description"/></xsl:if><sup><a class="definition" title="Additional description of the location" href="/article/about-accident-incident-database#LocationDescription">?</a></sup><br/>

    <p>Class<sup><a class="definition" title="International Scale of River Difficulty: I, II, III, IV, V, VI" href="/article/about-accident-incident-database#Class">?</a></sup>: <xsl:value-of select="class"/><br/>
    Flow<sup><a class="definition" title="Flow in cumecs, with a potential comment" href="/article/about-accident-incident-database#Flow">?</a></sup>:
    <xsl:choose>
      <xsl:when test="flow/value = 0">Unknown</xsl:when>
      <xsl:when test="not(flow/value)">Unknown</xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="flow/value"/>cu
        <xsl:if test="flow/comment"><xsl:value-of select="flow/comment"/></xsl:if>
      </xsl:otherwise>
    </xsl:choose>
    <xsl:if test="flow/relativeFlow">, &quot;<xsl:value-of select="flow/relativeFlow"/>&quot;</xsl:if><br/>
    Boat Type<sup><a class="definition" title="One of Canoe-1 person | Canoe-2 person | Kayak-Creek | Kayak-Playboat | Kayak-Touring | Kayak-Racing | Raft | Inflatable | Other" href="/article/about-accident-incident-database#BoatType">?</a></sup>: <xsl:value-of select="boat/type"/>/<xsl:value-of select="boat/description"/><br/>
    Trip Type<sup><a class="definition" title="One of Commerical | Club | Education | Private" href="/article/about-accident-incident-database#TypeType">?</a></sup>: <xsl:value-of select="trip"/></p>
    
    <div>
    Summary<sup><a class="definition" title="Objective summary of facts regarding the incident" href="/article/about-accident-incident-database#Summary">?</a></sup>: <xsl:apply-templates select="summary"/>
    </div>
    
    <div>
    Discussion<sup><a class="definition" title="Subjective analysis of the incident and recommendations for safe practice" href="/article/about-accident-incident-database#Discussion">?</a></sup>: <xsl:apply-templates select="discussion"/>
    </div>
    <xsl:apply-templates select="documents"/>
    
    <p style="margin-top: 5px; color: #aaaaaa;">Reported by<sup><a class="definition" title="The name of the person(s) reporting the incident" href="/article/about-accident-incident-database#Reporter">?</a></sup>: 
    <xsl:for-each select="reporter">
      <xsl:value-of select="name"/>
      <xsl:if test="position() != last()">, </xsl:if>
    </xsl:for-each>
    <br/>Created: <xsl:value-of select="substring-before(created,'T')"/>, changed: <xsl:value-of select="substring-before(changed,'T')"/>.</p>
  </div>
  </xsl:if>

</xsl:template>

<xsl:template match="summary|discussion">
  <xsl:apply-templates select="p|q|img"/>
</xsl:template>

<xsl:template match="documents">
  Sources<sup><a class="definition" title="Citations or links to supporting documentation including newspaper articles, MSA reports, articles and so on" href="/article/about-accident-incident-database#Documents">?</a></sup>:<br/>
  <xsl:apply-templates select="document"/>
  <xsl:if test="contains(document/a[@href],'pdf')">
    <br/>
    <xsl:call-template name="doAcrobat"/>
  </xsl:if>
</xsl:template>

<xsl:template match="document">
  <xsl:apply-templates select="@*|node()"/><xsl:if test="contains(.,'ODT')"> (Copy &amp; paste link)</xsl:if><br/>
</xsl:template>

<xsl:template name="doBody">
  <xsl:call-template name="doShowIncident"/>
</xsl:template>

</xsl:stylesheet>

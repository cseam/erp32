{atkconfig var="theme_logo" smartyvar="theme_logo"}
<div id="banner">

  <div id="bannerLogo"><a href="index.php"><img border="0" src="{if empty($theme_logo)}{atkthemeimg logo.jpg}{else}{$theme_logo}{/if}" alt="Logo" /></a></div>


  <div id="bannerCustomImage"></div>
  <div id="topLinks">
  
    <table id="topLinkTable" cellpadding="0" cellspacing="0">
      <tr>
        <td><span id="top-center">{foreach  from=$centerpiece_links item=link}{$link}&nbsp;&nbsp;|&nbsp;&nbsp;{/foreach}</span></td>
        {if $user}
		<td><span id="top-username">{atktext logged_in_as} {$user}</span>&nbsp;&nbsp;|&nbsp;&nbsp;</td>
        <td><span id="top-logout"><a href="index.php?atklogout=1" target="{$logouttarget}">{atktext logout}</a></span>&nbsp;&nbsp;</td>
        {/if}
        {if !$user}
		<td><span id="top-logout"><a href="index.php?atklogout=1" target="{$logouttarget}">Login</a></span>&nbsp;&nbsp;</td>
        {/if}
        {if $searchpiece}<td id="topLinkSearch"><span id="top-search">{$searchpiece}</span></td>{/if}
      </tr> 
    </table>
  </div>


</div>
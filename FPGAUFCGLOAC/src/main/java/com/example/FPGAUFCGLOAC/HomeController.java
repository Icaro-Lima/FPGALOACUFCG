package com.example.FPGAUFCGLOAC;

import java.util.concurrent.TimeUnit;

import org.springframework.cache.annotation.CacheEvict;
import org.springframework.context.annotation.Bean;
import org.springframework.http.CacheControl;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.handler.MappedInterceptor;
import org.springframework.web.servlet.mvc.WebContentInterceptor;

@Controller
public class HomeController {
	
	@CacheEvict(allEntries = true)
	@RequestMapping("/")
	public String index() {
		return "index.html";
	}
	
    @Bean
    public MappedInterceptor cacheControlInterceptor() {
        WebContentInterceptor webContentInterceptor = new WebContentInterceptor();
        webContentInterceptor.setCacheControl(CacheControl.maxAge(0, TimeUnit.SECONDS).cachePublic());
        webContentInterceptor.addCacheMapping(CacheControl.noStore().mustRevalidate(), "/index.html");
        // if using Spring Security CacheControlHeadersWriter:
        // webContentInterceptor.addCacheMapping(CacheControl.empty(), "/", "/index.html");
        return new MappedInterceptor(null, webContentInterceptor);
    }
	
}
